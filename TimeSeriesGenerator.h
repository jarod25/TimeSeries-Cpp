#ifndef TIMESERIESGENERATOR_H
#define TIMESERIESGENERATOR_H
#include <vector>

using namespace std;

class TimeSeriesGenerator
{
protected:
    int seed;

public:
    TimeSeriesGenerator(int seed);
    virtual ~TimeSeriesGenerator() = default;

    virtual vector<double> generateTimeSeries(int) = 0;
    static void printTimeSeries(const vector<double>&);
};


#endif //TIMESERIESGENERATOR_H