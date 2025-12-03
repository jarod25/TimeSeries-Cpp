#ifndef SINWAVEGENERATOR_H
#define SINWAVEGENERATOR_H
#include "TimeSeriesGenerator.h"

class SinWaveGenerator : public TimeSeriesGenerator
{
private:
    double amplitude;
    double frequency;
    double phase;

public:
    ~SinWaveGenerator() override;
    SinWaveGenerator(int seed, double amplitude, double frequency, double phase);

    vector<double> generateTimeSeries(int size) override;
};

#endif // SINWAVEGENERATOR_H
