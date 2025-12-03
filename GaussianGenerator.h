#ifndef GAUSSIANGENERATOR_H
#define GAUSSIANGENERATOR_H
#include "TimeSeriesGenerator.h"


class GaussianGenerator : public TimeSeriesGenerator
{
private:
    double mean;
    double stdDev;

    double boxMuller() const;

public:
    ~GaussianGenerator() override;
    GaussianGenerator(int seed, double mean, double stdDev);

    vector<double> generateTimeSeries(int) override;
};


#endif //GAUSSIANGENERATOR_H