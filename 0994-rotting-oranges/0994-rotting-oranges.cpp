class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        queue<vector<int>> q;
        int n=grid.size();
        int m=grid[0].size();
        for(int i=0;i<n;++i){
            for(int j=0;j<m;++j){
                if(grid[i][j]==2){
                    q.push({i,j,0});
                    grid[i][j]=0;
                }
            }
        }
        int ans=0;
       while(!q.empty()){
           vector<int> v=q.front();
           int row=v[0];
           int col=v[1];
           int cnt=v[2];
           ans=max(ans,v[2]);
           q.pop();
           int r[]={-1,1,0,0};
           int c[]={0,0,-1,1};
           for(int i=0;i<4;++i){
               int nrow=r[i]+row;
               int ncol=c[i]+col;
               if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && grid[nrow][ncol]==1){
                   grid[nrow][ncol]=0;
                    q.push({nrow,ncol,cnt+1});
                   
               }
           }
       } 
        for(auto it:grid){
            for(auto bt:it){
                if(bt!=0){
                    return -1;
                }
            }
        }
        return ans;
    }
};