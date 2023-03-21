class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
//         for(int i=0;i<nums.size();++i){
//             if(nums[i]<0){
//                 nums[i]*=-1;
                
//             }
//         }
        long long ans=0;
        long long pre=0;
        unordered_map<long long,int> mp;
        for(auto it:nums){
            pre+=abs(it);
            if(pre==0){
                ans++;
            }
            ans+=mp[pre];
            mp[pre]++;
        }
        return ans;
    }
};