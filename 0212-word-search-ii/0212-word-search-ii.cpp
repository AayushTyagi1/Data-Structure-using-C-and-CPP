class Solution {
public:
    int dx[4] = {0,1,0,-1};
    int dy[4] = {1,0,-1,0};
    vector<string> ans;
    
    
    class Trie{
      public:
        Trie *child[26];
        bool isEnd = false;
    };
    
    
    void insert(string &word, Trie* root){
        Trie* cur = root;
        for(char &ch : word){
            if(!cur->child[ch-'a']) cur->child[ch-'a']=new Trie();
            cur=cur->child[ch-'a'];
        }
        cur->isEnd=true;
    }
    
    
    void search(vector<vector<char>>& board, string &s, int x, int y, Trie* root){
        int row=board.size(), col=board[0].size();
        if(x<0 or x>=row or y<0 or y>=col or board[x][y]=='#') return;
        
        char ch = board[x][y];
        if(!root->child[ch-'a']){ 
            return;
        }
        
        board[x][y]='#';
        s.push_back(ch);
        
        if(root->child[ch-'a']->isEnd){
            root->child[ch-'a']->isEnd=false;
            ans.push_back(s);
        }
            
        for(int i=0;i<4;++i){
            int x1=x+dx[i], y1=y+dy[i];
            search(board,s,x1,y1,root->child[ch-'a']);
        }
        
        s.pop_back();
        board[x][y]=ch;
    }
    
    
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        Trie *root = new Trie();
        int row=board.size(), col=board[0].size();
        
        for(auto &w : words) insert(w,root);
        
        string s="";
        for(int i=0;i<row;++i){
            for(int j=0;j<col;++j){
                search(board,s,i,j,root);
            }
        }
        
        return ans;
    }
};