class Solution {
public:
    int rangeSum(vector<int>& nums, int n, int left, int right) {
        vector<int> v;
        int mod=1e9+7;
        
        for(int i=0;i<n;++i){
            long long sum=0;
            for(int j=i;j<n;++j){
                sum+=nums[j]%mod;
                 v.push_back(sum%mod);
            }
         
        }
        long long ans=0;
        sort(v.begin(),v.end());
        for(int i=left-1;i<right;++i){
            ans+=v[i]%mod;
        }
        return ans%mod;
        
    }
};