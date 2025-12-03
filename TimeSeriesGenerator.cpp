#include "TimeSeriesGenerator.h"

#include <iostream>
#include <vector>

using namespace std;

TimeSeriesGenerator::TimeSeriesGenerator(const int _seed) : seed(_seed)
{
}


void TimeSeriesGenerator::printTimeSeries(const vector<double>& timeSeries)
{
    for (const double time : timeSeries)
    {
        cout << time << " ";
    }
}
