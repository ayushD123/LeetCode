class Solution {
public:
    void helper(vector<int>& nums,int index,int target,int sum,int &ans){
        if(index>=nums.size()){
            if(sum==target){
                ans++;
               
            }
             return;
        }
        sum=sum+nums[index];
        helper(nums,index+1,target,sum,ans);
        sum=sum-nums[index];
        sum=sum-nums[index];
        helper(nums,index+1,target,sum,ans);
         sum=sum+nums[index];
        
    }
    
    int findTargetSumWays(vector<int>& nums, int target) {
        int ans=0;
        helper(nums,0,target,0,ans);
        return ans;
    }
};