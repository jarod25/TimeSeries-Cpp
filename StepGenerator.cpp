#include "StepGenerator.h"
#include <cstdlib>
#include <vector>

using namespace std;

StepGenerator::~StepGenerator() = default;

StepGenerator::StepGenerator(int seed) : TimeSeriesGenerator(seed)
{
    srand(seed);
}

vector<double> StepGenerator::generateTimeSeries(int size)
{
    vector<double> result;
    result.reserve(size);

    if (size <= 0) {
        return result;
    }

    double current = 0.0;
    result.push_back(current);

    for (int i = 1; i < size; i++)
    {
        int r = rand() % 2;

        if (r == 0)
        {
            current = double(rand() % 101);
        }

        result.push_back(current);
    }

    return result;
}
