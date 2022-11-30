//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution

{
    
    private:
    
    bool dfs(int i,int j,int vis[],vector<vector<int>>& grid){
       // if(grid[i][j]==2) return true;
        int n=grid.size();
        grid[i][j]=99;
        int delrow[]={-1,1,0,0};
        int delcol[]={0,0,1,-1};
        for(int it=0;it<4;++it){
            int newrow=delrow[it]+i;
            int newcol=delcol[it]+j;
            if(newrow<0 || newcol<0 || newrow>=n || newcol>=n) continue;
            if(grid[newrow][newcol]==2) return true;
            if(grid[newrow][newcol]==3){
            if(dfs(newrow,newcol,vis,grid)){
                return true;
            }
            }
        }
        return false;
    }
    public:
    //Function to find whether a path exists from the source to destination.
    bool is_Possible(vector<vector<int>>& grid) 
    {
        //code here
        
        int n=grid.size();
        int vis[n]={0};
        for(int i=0;i<n;++i){
            for(int j=0;j<n;++j){
                if(grid[i][j]==1){
                  return   dfs(i,j,vis,grid);
                }
            }
        }
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<vector<int>>grid(n, vector<int>(n, -1));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				cin >> grid[i][j];
			}
		}
		Solution obj;
		bool ans = obj.is_Possible(grid);
		cout << ((ans) ? "1\n" : "0\n");
	}
	return 0;
}
// } Driver Code Ends