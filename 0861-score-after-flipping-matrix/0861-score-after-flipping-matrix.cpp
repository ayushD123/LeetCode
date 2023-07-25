class Solution {
public:
    int matrixScore(vector<vector<int>>& grid) {
        for(int i=0;i<grid.size();++i){
          if(grid[i][0]==0){
              for(int j=0;j<grid[i].size();++j){
                if(grid[i][j]==0){
                grid[i][j]=1;
                }else{
                    grid[i][j]=0;
                }
             
              }
          }
        }
           
        for(int i=0;i<grid[0].size();++i){
            int cnt1=0,cnt0=0;
            for(int j=0;j<grid.size();++j){
                if(grid[j][i]==1){
                    cnt1++;
                }else{
                    cnt0++;
                }
            }
            if(cnt1<cnt0){
                cout<<cnt1<<" "<<cnt0<<" "<<i<<endl;
                  for(int j=0;j<grid.size();++j){
                if(grid[j][i]==1){
                    grid[j][i]=0;
                }else{
                    grid[j][i]=1;
                }
            }
            }
        }
        int n=grid[0].size();
        int ans=0;
         for(int i=0;i<grid.size();++i){
          for(int j=0;j<grid[i].size();++j){
          //    cout<<grid[i][j]<<" ";
              if(grid[i][j]==1){
                  ans+=pow(2,n-j-1);
              }
          }
             cout<<endl;
        }
        return ans;
    
    }
};