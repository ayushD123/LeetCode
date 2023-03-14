class Solution {
public:
    int leastBricks(vector<vector<int>>& wall) {
        unordered_map<int,int> mp;
        for(int j=0;j<wall.size();++j){
            vector<int> v=wall[j];
            int pre=0;
            for(int i=0;i<v.size()-1;++i){
                pre+=v[i];
                mp[pre]++;
            }
        }
        int ans=0;
        for(auto it:mp){
            ans=max(it.second,ans);
        }
        return wall.size()-ans;
    }
};