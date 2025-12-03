#include "SinWaveGenerator.h"
#include <cmath>
#include <vector>
#include <cstdlib>

using namespace std;

SinWaveGenerator::~SinWaveGenerator() = default;

SinWaveGenerator::SinWaveGenerator(int seed, double amplitude, double frequency, double phase)
    : TimeSeriesGenerator(seed), amplitude(amplitude), frequency(frequency), phase(phase)
{
    srand(seed);
}

vector<double> SinWaveGenerator::generateTimeSeries(int size)
{
    vector<double> result;
    result.reserve(size);

    for (int i = 0; i < size; i++)
    {
        double x = i;
        double value = amplitude * sin(frequency * x + phase);
        result.push_back(value);
    }

    return result;
}
