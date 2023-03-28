class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int n=nums.size();
        int left=0;
        int right=0;
        long long prod=1;
        int cnt=0;
        while(right<n){
            prod*=nums[right];
            right++;
           
                while(left<n && prod>=k){
                    prod/=nums[left];
                    left++;
                   
                }
               
                if(left<=right && prod<k)
                 cnt+=right-left;
            }
        
        return cnt;
    }
};