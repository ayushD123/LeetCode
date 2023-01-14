class Solution {
public:
    void dfs(int c,vector<int> adj[],vector<int> &v,int &minc,int vis[]){
        vis[c]=1;
        minc=min(minc,c);
        v.push_back(c);
        for(auto it:adj[c]){
            if(vis[it]==0){
                dfs(it,adj,v,minc,vis);
            }
        }
    }
    string smallestEquivalentString(string s1, string s2, string baseStr) {
        vector<int> adj[26];
        int n=s1.size();
        for(int i=0;i<s1.size();++i){
            adj[s1[i]-'a'].push_back(s2[i]-'a');
            adj[s2[i]-'a'].push_back(s1[i]-'a');
        }
        int vis[26]={0};
        unordered_map<int,int> mp;
        for(int i=0;i<26;++i){
            if(vis[i]==0){
                vector<int> v;
                int minchar=27;
                dfs(i,adj,v,minchar,vis);
                for(auto it:v){
                    cout<<it<<" ";
                    mp[it]=minchar;
                }
                cout<<minchar<<":"<<endl;
            }
        }
        string ans;
        for(char c:baseStr){
            ans+=(char)(mp[c-'a']+'a');
        }
        return ans;
    }
};