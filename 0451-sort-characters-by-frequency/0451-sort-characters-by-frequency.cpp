

class Solution {
    public:
       static bool comp(pair<char,int> p1,pair<char,int> p2){
            return p1.second>p2.second;
        }
	
    
public:
    string frequencySort(string s) {
         string ans;
        unordered_map<char,int> mp;
        for(auto it:s){
            mp[it]++;
            
        }
        vector<pair<char,int>> pm(mp.begin(),mp.end());
        sort(pm.begin(),pm.end(),comp);
        for(auto it:pm){
            for(int i=0;i<it.second;++i){
                ans.push_back(it.first);
            }
        }
return ans;
    }
};