class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int prod=1;
        int ans=nums[0];
        for(auto it:nums){
            prod*=it;
            ans=max(ans,prod);
            if(prod==0){
                prod=1;
            }
        }
        prod=1;
            for(int i=nums.size()-1;i>=0;i--){
                prod*=nums[i];
                ans=max(ans,prod);
                if(prod==0){
                prod=1;
            }
            }
        return ans;
    }
};