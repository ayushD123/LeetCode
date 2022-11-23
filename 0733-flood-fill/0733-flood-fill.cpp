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