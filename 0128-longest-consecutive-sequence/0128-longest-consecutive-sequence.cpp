class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
    unordered_map<int,bool> mp;
    unordered_map<int,bool> vis;
    for(auto it:nums){
        mp[it]=1;
    }
        int ans=0;
    for(auto it:nums){
        if(mp[it-1]) continue;
        if(vis[it]) continue;
        int x=it;
        int cnt=0;
        while(vis[x]==0 && mp[x]){
            vis[x]=1;
            cnt++;
            x++;
        }
        ans=max(ans,cnt);
    }
        return ans;
        
    }
};