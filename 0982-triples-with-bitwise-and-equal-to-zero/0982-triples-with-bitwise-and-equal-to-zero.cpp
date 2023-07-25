class Solution {
public:
    int countTriplets(vector<int>& nums) {
        unordered_map<int,int> mp;
        for(auto it:nums){
            for(auto xt:nums){
                mp[it&xt]++;
            }
        }
        int ans=0;
        for(auto it:nums){
            for(auto m:mp){
                if((it&m.first)==0){
                    ans+=m.second;
                }
            }
        }
        return ans;
    }
};