//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
    
    
  private:
  void dfs(int row,int col,vector<vector<char>> grid,vector<vector<int>> &vis){
      vis[row][col]=1;
      int n=grid.size();
      int m=grid[0].size();
       for(int i=-1;i<=1;++i){
           for(int j=-1;j<=1;++j){
               int tr=row+i;
               int tc=col+j;
              // if(row+i>n || row+i<0 || col+j>m || col+j<0) continue;
               if(tr>=0 && tr<n && tc>=0 && tc<m && grid[tr][tc]=='1' && vis[tr][tc]==0){
                   dfs(tr,tc,grid,vis);
               }
           }
       }
  }


  public:
    // Function to find the number of islands.
    int numIslands(vector<vector<char>>& grid) {
        // Code here
        int cnt=0;
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int> > vis(n,vector<int>(m,0));
        // int vis[n][m];
        // for(int i=0;i<n;++i){
        //     for(int j=0;j<m;++j){
        //         vis[i][j]=0;
        //     }
        // }
        for(int i=0;i<n;++i){
            for(int j=0;j<m;++j){
                if(vis[i][j]==0 && grid[i][j]=='1'){
                    cnt++;
                    dfs(i,j,grid,vis);
                }
            }
        }
        return cnt;
        
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, m;
        cin >> n >> m;
        vector<vector<char>> grid(n, vector<char>(m, '#'));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        int ans = obj.numIslands(grid);
        cout << ans << '\n';
    }
    return 0;
}
// } Driver Code Ends