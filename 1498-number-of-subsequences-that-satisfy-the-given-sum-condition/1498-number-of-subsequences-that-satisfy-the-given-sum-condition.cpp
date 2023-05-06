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
        for(int i=0;i<nums.size();++i){
            left=i;
            right=nums.size()-1;
            int t=-1;
            while(left<=right){
           int mid=(left+right)/2;
            if(nums[i]+nums[mid]<=target){
                left=mid+1;
                t=mid;
            }else{
                right=mid-1;
            }
                
        }
            if(t<0) break;
                ans+=pow2[t-i]%mod;
            ans=ans%mod;
        }
        
        return ans;
    }
};