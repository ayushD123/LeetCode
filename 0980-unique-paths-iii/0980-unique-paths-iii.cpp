class Solution {
public:
    void dfs(vector<vector<int>> &grid,int x,int y,int empty,int count,int &res){
        if(x>=grid.size() || y>=grid[0].size() || x<0 || y<0 || grid[x][y]==-1) return;
        
        
        //  if (grid[x][y] == 2) {
        //     if(empty == count) res++; 
        //     return;
        // }
        
        
      if(grid[x][y]==2){
          
      
        if(count==empty){
            res++;}
            return;
        }
        grid[x][y]=-1;
        dfs(grid,x+1,y,empty,count+1,res);
        dfs(grid,x,y+1,empty,count+1,res);
        dfs(grid,x-1,y,empty,count+1,res);
        dfs(grid,x,y-1,empty,count+1,res);
        grid[x][y]=0;
    }
    
    int uniquePathsIII(vector<vector<int>>& grid) {
        int empty=1;
        int res=0;
        int count=0;
      //  int vis[]={0};
        int start_x,start_y;
        for(int i=0;i<grid.size();++i){
            for(int j=0;j<grid[0].size();++j){
                if(grid[i][j]==1){
                    start_x=i;
                    start_y=j;
                }
                if(grid[i][j]==0){
                    empty++;
                    
                }
            }
        }
        dfs(grid,start_x,start_y,empty,count,res);
        return res;
    }
};