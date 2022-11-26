//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
    
private:
    void dfs(int row,int col,vector<vector<char>> &mat,vector<vector<int>> &pos){
        int n=mat.size();
        int m=mat[0].size();
        if(row>=n || col>=m || row<0 || col<0) return;
        if(pos[row][col]==0) return;
        if(mat[row][col]=='X') return;
        
        pos[row][col]=0;
        dfs(row+1,col,mat,pos);
        dfs(row,col+1,mat,pos);
        dfs(row-1,col,mat,pos);
        dfs(row,col-1,mat,pos);
        
        
    }
public:
    vector<vector<char>> fill(int n, int m, vector<vector<char>> mat)
    {
        // code here
        vector<vector<int>> pos(n,vector<int> (m,1));
        for(int i=0;i<n;++i){
            for(int j=0;j<m;++j){
                if(i==0 || i==(n-1) || j==0 || j==(m-1)){
                    if(mat[i][j]=='O' && pos[i][j]==1){
                        //pos[i][j]=0;
                        dfs(i,j,mat,pos);
                    }
                }
            }
        }
      //  vector<vector<char>> ans;
        vector<vector<char>> ans(n,vector<char> (m,'O'));
         for(int i=0;i<n;++i){
            for(int j=0;j<m;++j){
                if(pos[i][j]){
                    ans[i][j]='X';
                }
        }
         }
        return ans;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n, m;
        cin>>n>>m;
        vector<vector<char>> mat(n, vector<char>(m, '.'));
        for(int i = 0;i < n;i++)
            for(int j=0; j<m; j++)
                cin>>mat[i][j];
        
        Solution ob;
        vector<vector<char>> ans = ob.fill(n, m, mat);
        for(int i = 0;i < n;i++) {
            for(int j = 0;j < m;j++) {
                cout<<ans[i][j]<<" ";
            }
            cout<<"\n";
        }
    }
    return 0;
}
// } Driver Code Ends