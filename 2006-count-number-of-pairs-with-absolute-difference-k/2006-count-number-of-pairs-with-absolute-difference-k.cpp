class Solution {
public:
    int countKDifference(vector<int>& nums, int k) {
        unordered_map<int,int> mp;
        for(auto it:nums){
            mp[it]++;
        }
        int ans=0;
        for(auto it:nums){
            ans+=mp[(it-k)];
           
            ans+=mp[(it+k)];
            
        }
        return ans/2;
    }
};