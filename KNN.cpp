#include "KNN.h"
#include "Distance.h"
#include <algorithm> // sort
#include <utility>   // pair

using namespace std;

KNN::KNN(int k, const string& similarity_measure)
{
    this->k = k;
    this->similarity_measure = similarity_measure;
}

// ----------------------
// vote majoritaire
// ----------------------
int KNN::majorityVote(const vector<int>& labels) const
{
    if (labels.empty()) {
        return -1;
    }

    int maxLabel = labels[0];
    for (int v : labels) {
        if (v > maxLabel) {
            maxLabel = v;
        }
    }

    vector<int> count(maxLabel + 1, 0);

    for (int v : labels) {
        if (v >= 0 && v < (int)count.size()) {
            count[v]++;
        }
    }

    int bestLabel = 0;
    int bestCount = 0;

    for (int i = 0; i < (int)count.size(); i++) {
        if (count[i] > bestCount) {
            bestCount = count[i];
            bestLabel = i;
        }
    }

    return bestLabel;
}

// ----------------------
// prédire le label d'une seule série
// ----------------------
int KNN::predictOne(const vector<double>& query, const TimeSeriesDataset& trainData) const
{
    vector<pair<double,int>> distances;

    int n = trainData.getSize();

    for (int i = 0; i < n; i++) {
        const vector<double>& ts = trainData.getSeries(i);
        double d;

        if (similarity_measure == "dtw") {
            d = dtw_distance(query, ts);
        } else {
            // par défaut : euclidienne
            d = euclidean_distance(query, ts);
        }

        int label = trainData.getLabel(i);
        distances.push_back(make_pair(d, label));
    }

    // trie par distance croissante
    sort(distances.begin(), distances.end(),
         [](const pair<double,int>& a, const pair<double,int>& b){
             return a.first < b.first;
         });

    vector<int> knnLabels;

    int limit = k;
    if (limit > (int)distances.size()) {
        limit = distances.size();
    }

    for (int i = 0; i < limit; i++) {
        knnLabels.push_back(distances[i].second);
    }

    // cas k == 1 : majorityVote renverra juste ce label
    return majorityVote(knnLabels);
}

// ----------------------
// evaluate : calcule l'accuracy
// ----------------------
double KNN::evaluate(const TimeSeriesDataset& trainData,
                     const TimeSeriesDataset& testData,
                     const vector<int>& ground_truth) const
{
    int total = testData.getSize();
    if (total == 0 || (int)ground_truth.size() != total) {
        return 0.0;
    }

    int correct = 0;

    for (int i = 0; i < total; i++) {
        const vector<double>& query = testData.getSeries(i);
        int trueLabel = ground_truth[i];

        int predicted = predictOne(query, trainData);

        if (predicted == trueLabel) {
            correct++;
        }
    }

    return (double)correct / (double)total;
}
