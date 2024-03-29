class Solution {
public:
    int minPathSum(vector<vector<int>>& gr) {
        vector<vector<int>> dp(gr.size(),vector<int>(gr[0].size(),-1));
        for(int i = gr.size()-1; i>=0;i--){
            for(int j= gr[0].size()-1;j>=0;j--){
                if(i==gr.size()-1 && j==gr[0].size()-1) dp[i][j] = gr[i][j];
                else{
                    int a= 1e8, b= 1e8;
                    if(i < gr.size()-1)
                        a = dp[i+1][j];
                    if(j < gr[0].size()-1)
                        b= dp[i][j+1];
                    dp[i][j]=gr[i][j] + min(a,b);
                }
            }
        }
        return dp[0][0];
    }
};