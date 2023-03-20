class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
         unordered_map<int,int> mp;
        int pre=0;
        int cnt=0;
        for(auto it:nums){
            pre+=it;
            if(pre%k==0){
                cnt++;
            }
            int rem=pre%k;
            if(rem<0){
                rem+=k;
            }
            if(mp.find(rem)!=mp.end()){
                cnt+=mp[rem];
            }
            mp[rem]++;
        }
        return cnt;
    }
};