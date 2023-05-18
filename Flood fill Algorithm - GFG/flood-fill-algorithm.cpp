//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
    
private:
    void dfs(vector<vector<int>>& image, int sr, int sc, int newColor,int oldcolor,vector<vector<int>>& vis){
       // vis[sr][sc]=1;
       int n=image.size();
       int m=image[0].size();
        if(sr<0 || sc<0 || sr>=n || sc>=m || image[sr][sc]!=oldcolor || vis[sr][sc]==1  ) return;
        vis[sr][sc]=1;
        image[sr][sc]=newColor;
        dfs(image,sr+1,sc,newColor,oldcolor,vis);
        dfs(image,sr-1,sc,newColor,oldcolor,vis);
        dfs(image,sr,sc+1,newColor,oldcolor,vis);
        dfs(image,sr,sc-1,newColor,oldcolor,vis);
    }
    void dfs1(vector<vector<int>>& image, int sr, int sc, int newColor,int oldcolor,vector<vector<int>>& vis){
       // vis[sr][sc]=1;
       int n=image.size();
       int m=image[0].size();
    vis[sr][sc]=1;
    image[sr][sc]=newColor;
    for(int del_row=-1;del_row<=1;del_row++){
                for(int del_col=-1;del_col<=1;del_col++){
		    //not to check the diagonal elements.
                    if((del_row==-1 && del_col==-1) || (del_row==-1 && del_col==1) || (del_row==1 && del_col==-1) || (del_row==1 && del_col==1)){
                        continue;
                    }
                    int nrow=sr+del_row;
                    int ncol=sc+del_col;
                    if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && image[nrow][ncol]==oldcolor && vis[nrow][ncol]==0){
                        dfs1(image,nrow,ncol,newColor,oldcolor,vis);
                    }
                }
    }
    }

public:

    
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        // Code here
        int n=image.size();
        int m=image[0].size();
         vector<vector<int> > vis(n,vector<int>(m,0));
         int initial=image[sr][sc];
        dfs(image,sr,sc,newColor,initial,vis);
        return image;
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>>image(n, vector<int>(m,0));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++)
				cin >> image[i][j];
		}
		int sr, sc, newColor;
		cin >> sr >> sc >> newColor;
		Solution obj;
		vector<vector<int>> ans = obj.floodFill(image, sr, sc, newColor);
		for(auto i: ans){
			for(auto j: i)
				cout << j << " ";
			cout << "\n";
		}
	}
	return 0;
}
// } Driver Code Ends