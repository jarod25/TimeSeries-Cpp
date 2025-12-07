#include "GaussianGenerator.h"
#include <cstdlib>
#include <cmath>
#include <vector>

using namespace std;

#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif

// Destructeur (obligatoire car déclaré dans le .h)
GaussianGenerator::~GaussianGenerator() = default;

// Constructeur
GaussianGenerator::GaussianGenerator(int seed, double mean, double stdDev)
    : TimeSeriesGenerator(seed), mean(mean), stdDev(stdDev)
{
    srand(seed);
}

// Méthode Box-Muller pour générer une valeur gaussienne
double GaussianGenerator::boxMuller() const
{
    double u1 = 0.0;
    double u2 = 0.0;

    u1 = (rand() + 1.0) / (RAND_MAX + 2.0);
    u2 = (rand() + 1.0) / (RAND_MAX + 2.0);

    double z = sqrt(-2.0 * log(u1)) * cos(2.0 * M_PI * u2);

    return mean + z * stdDev;
}

// Génération d'une série temporelle de taille "size"
vector<double> GaussianGenerator::generateTimeSeries(int size)
{
    vector<double> result;
    result.reserve(size);

    for (int i = 0; i < size; ++i) {
        result.push_back(boxMuller());
    }

    return result;
}
