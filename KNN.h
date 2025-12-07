#ifndef KNN_H
#define KNN_H

#include <vector>
#include <string>
#include "TimeSeriesDataset.h"

using namespace std;

class KNN
{
private:
    int k;
    string similarity_measure;

    int majorityVote(const vector<int>& labels) const;
    int predictOne(const vector<double>& query, const TimeSeriesDataset& trainData) const;

public:
    KNN(int k, const string& similarity_measure);

    double evaluate(const TimeSeriesDataset& trainData,
                    const TimeSeriesDataset& testData,
                    const vector<int>& ground_truth) const;
};

#endif
