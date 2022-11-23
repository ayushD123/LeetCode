class Solution {
    
private:
   void dfs1(vector<vector<int>>& image, int sr, int sc, int newColor,int oldcolor){
       // vis[sr][sc]=1;
       int n=image.size();
       int m=image[0].size();
       int del_row[]={-1,0,1,0};
       int del_col[]={0,1,0,-1};
    
    image[sr][sc]=newColor;
    for(int i=0;i<4;++i){
                    int nrow=sr+del_row[i];
                    int ncol=sc+del_col[i];
                    if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && image[nrow][ncol]==oldcolor && image[nrow][ncol]!=newColor){
                        dfs1(image,nrow,ncol,newColor,oldcolor);
                    }
                }
    
    }

public:

    
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        // Code here
        int n=image.size();
        int m=image[0].size();
        
         int initial=image[sr][sc];
        dfs1(image,sr,sc,newColor,initial);
        return image;
    }
};