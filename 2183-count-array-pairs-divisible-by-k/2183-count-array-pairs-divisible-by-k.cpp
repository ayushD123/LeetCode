class Solution {
public:
    typedef long long ll;
    long long countPairs(vector<int>& nums, int k) {
        ll ans=0;
        unordered_map<ll,int> mp;
        for(auto it:nums){
            int gcd=__gcd(it,k);
            int req=k/gcd;
            for(auto it2:mp){
                if((it2.first%req)==0){
                    ans+=it2.second;
                }
                
            }
            mp[gcd]++;
        }
        return ans;
    }
};