class Solution {
public:
    bool isSafe(vector<vector<char>>&board, char ch, int i, int j)
    {
        return (i>=0 && j>=0 && i<board.size() && j<board[0].size() && board[i][j]==ch);
    }
    bool sol(vector<vector<char>>&board, string word, int i, int j, int ind, vector<vector<bool>> &v)
    {
        if(ind==word.length())
        {
            return true;
        }
        if(isSafe(board, word[ind], i, j) && !v[i][j])
        {
            v[i][j]=true;
             if(sol(board, word, i+1,j,ind+1,v)) return true;
             if(sol(board, word, i,j+1,ind+1,v)) return true;
             if(sol(board, word, i-1,j,ind+1,v)) return true;
             if(sol(board, word, i,j-1,ind+1,v)) return true;
            v[i][j]=false;
            
        }
        return false;
    }
    bool exist(vector<vector<char>>& board, string word) {
        vector<vector<bool>> v(board.size(),vector<bool>(board[0].size(),false));
        for(int i=0;i<board.size();i++)
        {
            for(int j=0;j<board[0].size();j++)
            {
                if(sol(board, word, i,j,0, v)) return true;
            }
        }
        return false;
    }
};