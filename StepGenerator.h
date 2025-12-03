#ifndef STEPGENERATOR_H
#define STEPGENERATOR_H
#include "TimeSeriesGenerator.h"


class StepGenerator : public TimeSeriesGenerator
{

public:
    ~StepGenerator() override;
    StepGenerator(int seed);

    vector<double> generateTimeSeries(int) override;
};


#endif //STEPGENERATOR_H