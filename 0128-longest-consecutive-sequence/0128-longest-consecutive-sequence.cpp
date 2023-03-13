class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
    unordered_map<int,bool> mp;
  
    for(auto it:nums){
        mp[it]=1;
    }
        int ans=0;
    for(auto it:nums){
        if(mp[it-1]) continue;
        int x=it;
        int cnt=0;
        while(mp[x]){
            cnt++;
            x++;
        }
        ans=max(ans,cnt);
    }
        return ans;
        
    }
};