class Solution {
    private:
    void dfs(int row,int col,vector<vector<int>>& vis,vector<vector<char>>& board){
        int n=board.size();
        int m=board[0].size();
        if(row<0 || row>=n || col<0 || col>=m) return;
        if(vis[row][col]) return;
        if(board[row][col]!='O') return;
        vis[row][col]=2;
        dfs(row+1,col,vis,board);
        dfs(row,col+1,vis,board);
        dfs(row-1,col,vis,board);
        dfs(row,col-1,vis,board);
    }
public:
    void solve(vector<vector<char>>& board) {
        int n=board.size();
        int m=board[0].size();
        vector<vector<int>> vis(n,vector<int> (m,0));
        for(int i=0;i<n;++i){
            for(int j=0;j<m;++j){
                if(i==0 || i==(n-1) || j==0 || j==(m-1)){
                    if(board[i][j]=='O' && vis[i][j]==0)
                    dfs(i,j,vis,board);
                }
            }
        }
        for(int i=0;i<n;++i){
            for(int j=0;j<m;++j){
                if(vis[i][j]!=2){
                    board[i][j]='X';
                }
            }
        }
        
    }
};