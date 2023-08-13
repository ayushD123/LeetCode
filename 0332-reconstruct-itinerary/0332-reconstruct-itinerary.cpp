class Solution {
public:
    bool dfs(map<string,vector<string>>& mp, string city, vector<string>& ans, int n) {
        if (ans.size() == n) return true;
        if (mp[city].size() == 0) return false;
            
        auto& destinations = mp[city];
        for (int i = 0; i < destinations.size(); ++i) {
            
            string dest = destinations[i];
            if(dest!="-1"){
                 ans.push_back(dest);
            destinations[i]="-1";
          //  destinations.erase(destinations.begin() + i);
            if (dfs(mp, dest, ans, n)) return true;
            ans.pop_back();
            destinations[i]=dest;
           // destinations.insert(destinations.begin() + i, dest); // Insert back at the correct position
            }
           
        }
        return false;
    }
    
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        sort(tickets.begin(), tickets.end());
        map<string,vector<string>> mp;
        for (auto it : tickets) {
            mp[it[0]].push_back(it[1]);
        }
        vector<string> ans;
        ans.push_back("JFK");
        dfs(mp, "JFK", ans, tickets.size() + 1);
        return ans;
    }
};
