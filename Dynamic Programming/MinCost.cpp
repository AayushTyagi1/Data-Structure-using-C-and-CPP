#include <iostream>
#include <climits>
using namespace std;

#define N 4

int minCostRec(int cost[][N], int s, int d)
{
    if (s == d || s + 1 == d)
        return cost[s][d];

    int min = cost[s][d];
    for (int i = s + 1; i < d; i++)
    {
        int c = minCostRec(cost, s, i) +
                minCostRec(cost, i, d);
        if (c < min)
            min = c;
    }
    return min;
}

int main()
{
    int cost[N][N] = {{0, 15, 80, 90},
                      {INT_MAX, 0, 40, 50},
                      {INT_MAX, INT_MAX, 0, 70},
                      {INT_MAX, INT_MAX, INT_MAX, 0}};
    cout << "The Minimum cost to reach station "
         << N << " is " << minCostRec(cost, 0, N - 1);
    return 0;
}