class Solution {
public:
    string reorganizeString(string s) {
        int n=s.size();
        unordered_map<char,int> mp;
        for(auto it:s){
            mp[it]++;
        }
        priority_queue<pair<int,char>> pq;
        for(auto &it:mp){
            if(it.second>(n+1)/2){
                return "";
            }
            pq.push({it.second,it.first});
        }
        string ans(n,' ');
        int ind=0;
        while(pq.size()>0){
            pair<int,char> p=pq.top();
            while(p.first){
                if(ind>=n){
                    ind=1;
                }
                ans[ind]=p.second;
                ind+=2;
                p.first--;
            }
            pq.pop();
        }
        return ans;
    }
};