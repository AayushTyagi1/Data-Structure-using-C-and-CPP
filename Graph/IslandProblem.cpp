#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int dfs(vector<vector<int>> &grid, int row, int col)
{
    int m = grid.size();
    int n = grid[0].size();
    int area = 1;
    grid[row][col] = 0;
    vector<int> dir({-1, 0, 1, 0, -1});
    for (int i = 0; i < 4; i++)
    {
        int r = row + dir[i], c = col + dir[i + 1];
        if (r >= 0 && r < m && c >= 0 && c < n && grid[r][c] == 1)
            area += dfs(grid, r, c);
    }
    return area;
}

vector<int> largestIsland(vector<vector<int>> grid)
{
    int m = grid.size();
    int n = grid[0].size();
    vector<int> maxArea;
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            if (grid[i][j] == 1)
                maxArea.push_back(dfs(grid, i, j));

    return maxArea;
}

int main()
{
    vector<vector<int>> grid = {{0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0},
                                {0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0},
                                {0, 1, 1, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0},
                                {0, 1, 0, 0, 1, 1, 0, 0, 1, 0, 1, 0, 0},
                                {0, 1, 0, 0, 1, 1, 0, 0, 1, 1, 1, 0, 0},
                                {0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 0},
                                {0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0},
                                {0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0}};

    vector<int> ans = largestIsland(grid);
    sort(ans.begin(), ans.end());
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }

    return 0;
}