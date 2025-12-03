#include "Distance.h"
#include <cmath>

double euclidean_distance(const vector<double>& a, const vector<double>& b)
{
    int n = a.size();
    int m = b.size();
    
    int size = (n < m) ? n : m;

    double sum = 0.0;

    for (int i = 0; i < size; i++)
    {
        double diff = a[i] - b[i];
        sum += diff * diff;
    }

    return sqrt(sum);
}

double dtw_distance(const vector<double>& a, const vector<double>& b)
{
    int n = a.size();
    int m = b.size();

    // Matrice DTW de taille n x m
    vector<vector<double>> dp(n, vector<double>(m, 0.0));

    // Initialisation de dp[0][0]
    dp[0][0] = fabs(a[0] - b[0]);

    // Première colonne
    for (int i = 1; i < n; i++) {
        dp[i][0] = dp[i - 1][0] + fabs(a[i] - b[0]);
    }

    // Première ligne
    for (int j = 1; j < m; j++) {
        dp[0][j] = dp[0][j - 1] + fabs(a[0] - b[j]);
    }

    // Remplissage du reste
    for (int i = 1; i < n; i++) {
        for (int j = 1; j < m; j++) {

            double cost = fabs(a[i] - b[j]);

            double minPrev = dp[i - 1][j];
            if (dp[i][j - 1] < minPrev) minPrev = dp[i][j - 1];
            if (dp[i - 1][j - 1] < minPrev) minPrev = dp[i - 1][j - 1];

            dp[i][j] = cost + minPrev;
        }
    }

    // La distance DTW est dans dp[n-1][m-1]
    return dp[n - 1][m - 1];
}