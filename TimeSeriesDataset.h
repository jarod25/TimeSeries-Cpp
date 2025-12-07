#ifndef TIMESERIESDATASET_H
#define TIMESERIESDATASET_H

#include <vector>

using namespace std;

class TimeSeriesDataset
{
private:
    bool znormalize;
    bool isTrain;

    vector<vector<double>> data;
    vector<int> labels;

    int maxLength;
    int numberOfSamples;

    double mean(const vector<double>& series);
    double stddev(const vector<double>& series, double mean);

public:
    // constructeur utilisé dans le main : TimeSeriesDataset(false, true) etc.
    TimeSeriesDataset(bool znormalize, bool isTrain);

    // optionnel, au cas où tu veux un constructeur par défaut
    TimeSeriesDataset() : TimeSeriesDataset(false, false) {}

    void addTimeSeries(const vector<double>& series, int label);

    vector<double> zNormalize(const vector<double>& series);
    void normalizeAll();

    const vector<double>& getSeries(int index) const;
    int getLabel(int index) const;

    int getSize() const;
    int getMaxLength() const;
};

#endif
