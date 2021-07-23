#include <bits/stdc++.h>
using namespace std;
#define MAX 100
int N, M;
bool isSafe(vector<vector<int>> mat, vector<vector<int>> visited, int x, int y)
{
    if (mat[x][y] == 0 || visited[x][y])
    {
        return false;
    }
    return true;
}

bool isValid(int x, int y)
{
    if (x < M && y < N && x >= 0 && y >= 0)
    {
        return true;
    }
    return false;
}

void findShortestPath(vector<vector<int>> mat, vector<vector<int>> visited, int i, int j,
                      int x, int y, int &min_dist, int dist)
{
    if (i == x && j == y)
    {
        min_dist = min(dist, min_dist);
        return;
    }

    visited[i][j] = 1;

    if (isValid(i + 1, j) && isSafe(mat, visited, i + 1, j))
    {
        findShortestPath(mat, visited, i + 1, j, x, y, min_dist, dist + 1);
    }
    if (isValid(i, j + 1) && isSafe(mat, visited, i, j + 1))
    {
        findShortestPath(mat, visited, i, j + 1, x, y, min_dist, dist + 1);
    }
    if (isValid(i - 1, j) && isSafe(mat, visited, i - 1, j))
    {
        findShortestPath(mat, visited, i - 1, j, x, y, min_dist, dist + 1);
    }
    if (isValid(i, j - 1) && isSafe(mat, visited, i, j - 1))
    {
        findShortestPath(mat, visited, i, j - 1, x, y, min_dist, dist + 1);
    }

    visited[i][j] = 0;
}
int main()
{
    cin >> M >> N;
    string arr[M];
    for (int i = 0; i < M; i++)
    {
        cin >> arr[i];
    }
    vector<vector<int>> a(M, vector<int>(N));
    for (int i = 0; i < M; i++)
    {
        for (int j = 0; j < N; j++)
            if (arr[i][j] == '.' || arr[i][j] == '#')
                a[i][j] = 1;
            else
                a[i][j] = 0;
    }
    vector<vector<int>> visited(M, vector<int>(N));
    for (int i = 0; i < M; i++)
    {
        for (int j = 0; j < N; j++)
            visited[i][j] = 0;
    }
    int min_dist = INT_MAX;
    findShortestPath(a, visited, 0, 0, M - 1, N - 1, min_dist, 0);

    if (min_dist != INT_MAX)
    {
        cout << min_dist << endl;
    }
    else
    {
        cout << -1 << endl;
    }

    for (int i = 0; i < M; i++)
    {
        for (int j = 0; j < N; j++)
            if (arr[i][j] == '.' || arr[i][j] == '*')
                a[i][j] = 1;
            else
                a[i][j] = 0;
    }
    for (int i = 0; i < M; i++)
    {
        for (int j = 0; j < N; j++)
            visited[i][j] = 0;
    }

    min_dist = INT_MAX;
    findShortestPath(a, visited, 0, 0, M - 1, N - 1, min_dist, 0);

    if (min_dist != INT_MAX)
    {
        cout << min_dist << endl;
    }
    else
    {
        cout << -1 << endl;
    }
}