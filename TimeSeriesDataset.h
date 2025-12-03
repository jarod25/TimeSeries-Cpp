#ifndef TIMESERIESDATASET_H
#define TIMESERIESDATASET_H

#include <vector>

using namespace std;

class TimeSeriesDataset
{
private:
    vector<vector<double>> data;
    vector<int> labels;

    double mean(const vector<double>& series);
    double stddev(const vector<double>& series, double mean);

public:
    TimeSeriesDataset() = default;

    void addTimeSeries(const vector<double>& series, int label);

    vector<double> zNormalize(const vector<double>& series);
    void normalizeAll();

    const vector<double>& getSeries(int index);
    int getLabel(int index) const;
    int getSize() const;
};

#endif
