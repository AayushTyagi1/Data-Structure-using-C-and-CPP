class Solution {
    public int countNegatives(int[][] grid) {
     
        int n = grid.length;
        int m = grid[0].length;
        return function(n,m,grid);
    }
    
    public int function(int n,int m,int[][]arr)
    {
        int i = 0;
        int j = m-1;
        int count=0;
        while(i<n && j>=0)
        {
            if(arr[i][j]<0)
            {
                count = count+(n-i);
                j--;
            }
            else
            {
                i++;
            }
        }
        return count;
    }
};