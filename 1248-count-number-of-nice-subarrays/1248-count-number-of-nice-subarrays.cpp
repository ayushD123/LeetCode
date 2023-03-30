class Solution {
public:
    

    int numberOfSubarrays(vector<int>& nums, int k) {
        int odd=0;
        int ans=0;
        int left=0;
        int pre=0;
        int right=0;
        int n=nums.size();
        while(right<n){
            if(nums[right]%2!=0){
                odd++;
                pre=0;
            }
            while(k==odd && left<=right){
                if(nums[left]%2!=0){
                odd--;
            }
                left++;
                pre++;
                
            }
            right++;
            ans+=pre;
        }
        return ans;
    }
};