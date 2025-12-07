#include "TimeSeriesDataset.h"
#include <cmath>

using namespace std;

TimeSeriesDataset::TimeSeriesDataset(bool znormalize, bool isTrain)
{
    this->znormalize = znormalize;
    this->isTrain = isTrain;
    this->maxLength = 0;
    this->numberOfSamples = 0;
}

void TimeSeriesDataset::addTimeSeries(const vector<double>& series, int label)
{
    vector<double> s = series;

    if (znormalize) {
        s = zNormalize(series);
    }

    data.push_back(s);
    labels.push_back(label);

    numberOfSamples++;

    if ((int)s.size() > maxLength) {
        maxLength = (int)s.size();
    }
}

double TimeSeriesDataset::mean(const vector<double>& series)
{
    if (series.empty()) {
        return 0.0;
    }

    double sum = 0.0;
    for (double v : series) {
        sum += v;
    }

    return sum / series.size();
}

double TimeSeriesDataset::stddev(const vector<double>& series, double m)
{
    if (series.empty()) {
        return 0.0;
    }

    double sum = 0.0;
    for (double v : series) {
        double diff = v - m;
        sum += diff * diff;
    }

    double variance = sum / series.size();
    return sqrt(variance);
}

vector<double> TimeSeriesDataset::zNormalize(const vector<double>& series)
{
    vector<double> result;
    result.reserve(series.size());

    if (series.empty()) {
        return result;
    }

    double m = mean(series);
    double s = stddev(series, m);

    if (s == 0.0) {
        // Série plate : tout identique → on renvoie des 0
        for (int i = 0; i < (int)series.size(); i++) {
            result.push_back(0.0);
        }
        return result;
    }

    for (double v : series) {
        double z = (v - m) / s;
        result.push_back(z);
    }

    return result;
}

void TimeSeriesDataset::normalizeAll()
{
    for (int i = 0; i < (int)data.size(); i++) {
        data[i] = zNormalize(data[i]);
    }
}

const vector<double>& TimeSeriesDataset::getSeries(int index) const
{
    return data[index];
}

int TimeSeriesDataset::getLabel(int index) const
{
    return labels[index];
}

int TimeSeriesDataset::getSize() const
{
    return numberOfSamples;
}

int TimeSeriesDataset::getMaxLength() const
{
    return maxLength;
}
