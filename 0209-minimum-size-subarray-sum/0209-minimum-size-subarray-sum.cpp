class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int ans=999999999;
        int left=0;
        int right=0;
        int n=nums.size();
        int sum=0;
        while(right<n){
            sum+=nums[right];
            right++;
            while(left<n && sum>=target){
                ans=min(ans,right-left);
                sum-=nums[left];
                left++;
            }
        }
        if(ans!=999999999)
      return ans;    
        return 0;
    }
};