class Solution {
public:
    int numSubseq(vector<int>& nums, int target) {
        int left=0;
        int mod=1000000007;
        int right=nums.size()-1;
        vector<int> pow2(nums.size());
        pow2[0]=1;
        for(int i=1;i<nums.size();++i){
            pow2[i]=(pow2[i-1]*2)%mod;
        }
        
        sort(nums.begin(),nums.end());
        int ans=0;
        while(left<=right){
            if(nums[left]+nums[right]<=target){
                
                ans+=pow2[right-left]%mod;
                ans=ans%mod;
                left++;
            }else{
                right--;
            }
        }
        return ans;
    }
};