class Solution {
public:
    int solve(int i,int j,vector<vector<int>>& grid,vector<vector<int>>& dp){
        if(i==(grid.size()-1)){
            return grid[i][j];
        }
        if(dp[i][j]!=-1) return dp[i][j];
        int bel=grid[i][j]+solve(i+1,j,grid,dp);
        int dia=grid[i][j]+solve(i+1,j+1,grid,dp);
        return dp[i][j]=min(bel,dia);
    }
    int minimumTotal(vector<vector<int>>& grid) {
        int m = grid.size();
        
        vector<vector<int>> dp;
        for(int i=0;i<m;++i){
            vector<int> v;
            for(int j=0;j<grid[i].size();++j){
                v.push_back(-1);
            }
            dp.push_back(v);
        }
        return solve(0,0,grid,dp);
    }
};