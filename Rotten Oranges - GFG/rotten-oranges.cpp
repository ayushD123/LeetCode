//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution 
{
    
    private:
    
    
    
    public:
    //Function to find minimum time required to rot all oranges. 
    int orangesRotting(vector<vector<int>>& grid) {
        // Code here
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>> vis(n,vector<int> (m,0));
        queue<vector<int>> q;
        for(int i=0;i<n;++i){
            for(int j=0;j<m;++j){
                if(grid[i][j]==2){
                    vector<int> v={i,j,0};
                    q.push(v);
                    vis[i][j]=1;
                }
            }
        }
        
        int ans=0;
        while(!q.empty()){
            vector<int> t=q.front();
            q.pop();
            int row=t[0];
            int col=t[1];
            ans=t[2];
           int del_row[]={-1,0,1,0};
            int del_col[]={0,1,0,-1};
            for(int i=0;i<4;++i){
                int nrow=row+del_row[i];
                int ncol=col+del_col[i];
                if(nrow>=n || nrow<0 || ncol>=m || ncol<0) continue;
                if(vis[nrow][ncol]) continue;
                if(grid[nrow][ncol]==1){
                    vector<int> v;
                    v.push_back(nrow);
                    v.push_back(ncol);
                    v.push_back(t[2]+1);
                    q.push(v);
                    vis[nrow][ncol]=1;
                    grid[nrow][ncol]=2;
                }
            }
        }
         for(int i=0;i<n;++i){
            for(int j=0;j<m;++j){
                if(grid[i][j]==1){
                   return -1;
                }
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>>grid(n, vector<int>(m, -1));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				cin >> grid[i][j];
			}
		}
		Solution obj;
		int ans = obj.orangesRotting(grid);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends