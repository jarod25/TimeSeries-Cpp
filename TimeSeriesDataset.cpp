#include "TimeSeriesDataset.h"
#include <cmath>

using namespace std;

void TimeSeriesDataset::addTimeSeries(const vector<double>& series, int label)
{
    data.push_back(series);
    labels.push_back(label);
}

double TimeSeriesDataset::mean(const vector<double>& series)
{
    double sum = 0.0;

    for (double v : series) {
        sum += v;
    }

    return sum / series.size();
}

double TimeSeriesDataset::stddev(const vector<double>& series, double m)
{
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

    double m = mean(series);
    double s = stddev(series, m);

    if (s == 0) {
        // Tous les éléments sont identiques → série plate
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

const vector<double>& TimeSeriesDataset::getSeries(int index)
{
    return data[index];
}

int TimeSeriesDataset::getLabel(int index) const
{
    return labels[index];
}

int TimeSeriesDataset::getSize() const
{
    return data.size();
}
