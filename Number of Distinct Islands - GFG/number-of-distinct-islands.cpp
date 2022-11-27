//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {

    private:
    void dfs(int row,int col,vector<vector<int>>& vis,set<vector<pair<int,int>>> &st,vector<vector<int>>& grid,int prow,int pcol,vector<pair<int,int>> &v){
        int n=grid.size();
        int m=grid[0].size();
        vis[row][col]=1;
        v.push_back({(prow-row),(pcol-col)});
        int delrow[]={-1,1,0,0};
        int delcol[]={0,0,-1,1};
       // if(row>=n || col>=n || row<0 || col<0) return;
        // for(int i=-1;i<=1;++i){
        //     for(int j=-1;j<=1;++j){
        //         int nrow=row+i;
        //         int ncol=col+i;
        //         if(nrow>=n || ncol>=n || nrow<0 || ncol<0) continue;
        //         if(vis[nrow][ncol]) continue;
        //         if(grid[nrow][ncol]==0) continue;
        //         dfs(nrow,ncol,vis,st,grid,prow,pcol,v);
        //     }
        // }
        
        for(int i=0;i<4;++i){
             int nrow=row+delrow[i];
                int ncol=col+delcol[i];
                if(nrow>=n || ncol>=m || nrow<0 || ncol<0) continue;
                if(vis[nrow][ncol]) continue;
                if(grid[nrow][ncol]==0) continue;
                dfs(nrow,ncol,vis,st,grid,prow,pcol,v);
        }
        
        
    }

  public:
    int countDistinctIslands(vector<vector<int>>& grid) {
        // code here
        int n=grid.size();
        int m=grid[0].size();
        set<vector<pair<int,int>>> st;
        int cnt=0;
        vector<vector<int>> vis(n,vector<int>(m,0));
        for(int i=0;i<n;++i){
            for(int j=0;j<m;++j){
                if(vis[i][j]==0 && grid[i][j]==1){
                    vis[i][j]=1;
                    vector<pair<int,int>> v;
                    dfs(i,j,vis,st,grid,i,j,v);
                    st.insert(v);
                    cnt++;
                }
            }
        }
        return st.size();
    }
};


//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> grid(n, vector<int>(m));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        cout << obj.countDistinctIslands(grid) << endl;
    }
}
// } Driver Code Ends