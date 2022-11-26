//same as replace 0's with X just change 0-->1 nd X-->0 nd put cnt

//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;
 

// } Driver Code Ends
// User function Template for C++

class Solution {
    private:
      void dfs(int row,int col,vector<vector<int>> &mat,vector<vector<int>> &surr){
        int n=mat.size();
        int m=mat[0].size();
        if(row>=n || col>=m || row<0 || col<0) return;
        if(surr[row][col]==0) return;
        if(mat[row][col]==0) return;
        
        surr[row][col]=0;
        dfs(row+1,col,mat,surr);
        dfs(row,col+1,mat,surr);
        dfs(row-1,col,mat,surr);
        dfs(row,col-1,mat,surr);
        
        
    }
  public:
    int numberOfEnclaves(vector<vector<int>> &mat) {
        // Code here
        int n=mat.size();
        int m=mat[0].size();
        vector<vector<int>> surr(n,vector<int> (m,1));
        for(int i=0;i<n;++i){
            for(int j=0;j<m;++j){
                if(i==0 || i==(n-1) || j==0 || j==(m-1)){
                    if(mat[i][j]==1 && surr[i][j]==1){
                        //pos[i][j]=0;
                        dfs(i,j,mat,surr);
                    }
                }
            }
        }
        int cnt=0;
      //  vector<vector<char>> ans;
      //  vector<vector<char>> ans(n,vector<char> (m,'O'));
         for(int i=0;i<n;++i){
            for(int j=0;j<m;++j){
                if(surr[i][j]==1 && mat[i][j]==1){
                  //  mat[i][j]='X';
                  cnt++;
                }
        }
         }
        return cnt;
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
        cout << obj.numberOfEnclaves(grid) << endl;
    }
}
// } Driver Code Ends
