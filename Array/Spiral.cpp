vector<int> spiralOrder(vector<vector<int>> &matrix)
{
    int up = 0, down = matrix.size() - 1;
    int left = 0, right = matrix[0].size() - 1;
    vector<int> v;
    while (up <= down && left <= right)
    {
        for (int i = left; i <= right; i++)
        {
            v.push_back(matrix[up][i]);
        }
        up++;
        for (int i = up; i <= down; i++)
        {
            v.push_back(matrix[i][right]);
        }
        right--;
        if (up <= down)
        {
            for (int i = right; i >= left; i--)
            {
                v.push_back(matrix[down][i]);
            }
            down--;
        }
        if (left <= right)
        {
            for (int i = down; i >= up; i--)
            {
                v.push_back(matrix[i][left]);
            }
            left++;
        }
    }
    return v;
}