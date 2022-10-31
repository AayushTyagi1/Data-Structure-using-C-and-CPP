class Solution {
public:
    bool isToeplitzMatrix(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        
        for(int i=0;i<m;i++)
        {
            int p = matrix[i][0];
            int ind=i;
            for(int j=0;j<n && ind<m;j++)
            {
                if(matrix[ind++][j]!=p)
                    return false;
            }
        }
        for(int i=1;i<n;i++)
        {
            int p = matrix[0][i];
            int ind=i;
            for(int j=0;j<m && ind<n;j++)
            {
                if(matrix[j][ind++]!=p)
                    return false;
            }
        }
        return true;
    }
};