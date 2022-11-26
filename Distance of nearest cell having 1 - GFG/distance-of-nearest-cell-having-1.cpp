//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution 
{
    public:
    //Function to find distance of nearest 1 in the grid for each cell.
	vector<vector<int>>nearest(vector<vector<int>>grid)
	{
	  int n=grid.size();
        int m=grid[0].size();
       // vector<vector<int>> vis(n,vector<int> (m,0));
        vector<vector<int>> anss(n,vector<int> (m,0));
        queue<vector<int>> q;
        for(int i=0;i<n;++i){
            for(int j=0;j<m;++j){
                if(grid[i][j]==1){
                    vector<int> v={i,j,0};
                    q.push(v);
                  //  vis[i][j]=1;
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
            anss[row][col]=ans;
           int del_row[]={-1,0,1,0};
            int del_col[]={0,1,0,-1};
            for(int i=0;i<4;++i){
                int nrow=row+del_row[i];
                int ncol=col+del_col[i];
                if(nrow>=n || nrow<0 || ncol>=m || ncol<0) continue;
              //  if(vis[nrow][ncol]) continue;
                if(grid[nrow][ncol]==0){
                    vector<int> v;
                    v.push_back(nrow);
                    v.push_back(ncol);
                    v.push_back(t[2]+1);
                    q.push(v);
                   // vis[nrow][ncol]=1;
                   grid[nrow][ncol]=2;
                }
            }
        }
        //  for(int i=0;i<n;++i){
        //     for(int j=0;j<m;++j){
        //         if(grid[i][j]==1){
        //           return -1;
        //         }
        //     }
        // }
        return anss;
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
		vector<vector<int>> ans = obj.nearest(grid);
		for(auto i: ans){
			for(auto j: i){
				cout << j << " ";
			}
			cout << "\n";
		}
	}
	return 0;
}
// } Driver Code Ends