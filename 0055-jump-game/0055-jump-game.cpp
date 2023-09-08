class Solution {
    vector<int> dp;
public:
    
    bool helper(vector<int>& nums,int ind,int j){
        if(ind>=(nums.size()-1)) return 1;
        if(dp[ind]!=-1) return dp[ind];
        for(int i=1;i<=j;++i){
            if((ind+i-1)>=nums.size()) return 1;
            if(helper(nums,ind+i,nums[ind+i])){
               return dp[ind]=1;
            }
        }
        return dp[ind]=0;
    }
    bool canJump(vector<int>& nums) {
        if(nums.size()==1) return 1;
        dp.assign(nums.size()+1,-1);
       return helper(nums,0,nums[0]);
    }
};