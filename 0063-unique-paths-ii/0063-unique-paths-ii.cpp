class Solution {
public:
    int solve(int m,int n,  vector<vector<int>> &dp,vector<vector<int>>& obs){
        if(m==0 && n==0 && obs[m][n]==0){
            return 1;
        }
        if(m<0 || n<0) return 0;
        if(obs[m][n]==1) return 0;
        if(dp[m][n]!=(-1)) return dp[m][n];
        int left=solve(m-1,n,dp,obs);
        int top=solve(m,n-1,dp,obs);
        return dp[m][n]=left+top;
    }
    int uniquePathsWithObstacles(vector<vector<int>>& obs) {
        int m=obs.size();
        int n=obs[0].size();
          vector<vector<int>> dp;
        for(int i=0;i<m;++i){
            vector<int> t(n,-1);
            dp.push_back(t);
        }
        return solve(m-1,n-1,dp,obs); 
    }
};