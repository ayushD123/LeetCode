class Solution {
public:
    //memo
    // int solve(int m,int n,  vector<vector<int>> &dp){
    //     if(m==0 && n==0){
    //         return 1;
    //     }
    //     if(m<0 || n<0) return 0;
    //     if(dp[m][n]!=(-1)) return dp[m][n];
    //     int left=solve(m-1,n,dp);
    //     int top=solve(m,n-1,dp);
    //     return dp[m][n]=left+top;
    // }
    /*
        steps to convert memo into tab-
            1)write base case inside dp array
            2)write all possible states through for loops
            3)copy recurrence relation and use dp array
    */
    //tab
    int tab(int m,int n,  vector<vector<int>> &dp){
        dp[0][0]=1; //write base case inside dp array
        for(int i=0;i<m;++i){ //write all possible states through for loops for each i=0 there are 0->n similarly for i=1,2...m
            for(int j=0;j<n;++j){
                if(i==0 && j==0) continue;
                int left=0;
                int top=0;
                if(i>0){
                     left=dp[i-1][j]; //just copied the recurrence and used dp instead of function name
                }
               if(j>0){
                top=dp[i][j-1];
               }
                
                dp[i][j]=left+top;
            }
        }
        return dp[m-1][n-1];
    }
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp;
        for(int i=0;i<m;++i){
            vector<int> t(n,-1);
            dp.push_back(t);
        }
    //    return solve(m-1,n-1,dp); // m and n given as 1 based
        return tab(m,n,dp);
        
    }
};