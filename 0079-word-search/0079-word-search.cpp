class Solution {
private:
    bool dfs(int row,int col,vector<vector<char>>& board, string word, vector<vector<int>> &vis,int 
             
             cnt){
        int n=board.size();
        int m=board[0].size();
        if(cnt==word.length()) return true;;
        if(row<0 || col<0 || row>=n || col>=m) return false;;
        if(vis[row][col]) return false;
        if(board[row][col]!=word[cnt]) return false;
        cnt+=1;
        vis[row][col]=1;
        bool ans=(dfs(row+1,col,board,word,vis,cnt) || 
        dfs(row-1,col,board,word,vis,cnt) || 
        dfs(row,col+1,board,word,vis,cnt) || 
        dfs(row,col-1,board,word,vis,cnt));
        vis[row][col]=0;
        
        
        return ans;
    }
public:
    bool exist(vector<vector<char>>& board, string word) {
        int n=board.size();
        int m=board[0].size();
        vector<vector<int>> vis(n,vector<int>(m,0));
        int cnt=0;
        for(int i=0;i<n;++i){
            for(int j=0;j<m;++j){
                if(board[i][j]==word[0]){
                    vector<vector<int>> temp=vis;
                    if(dfs(i,j,board,word,temp,cnt)){
                    return true;
                }
            }
        }
        }
        return false;
    }
};