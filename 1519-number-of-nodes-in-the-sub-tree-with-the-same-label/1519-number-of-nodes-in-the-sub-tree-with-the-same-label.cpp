class Solution {
public:
    vector<int> dfs(int node,int par,vector<vector<int>> &adj,vector<int>  &ans,string &labels){
        vector<int> temp(26);
        temp[labels[node]-'a']=1;
        for(auto& child:adj[node]){
            if(child==par) continue;
            vector<int> count=dfs(child,node,adj,ans,labels);
            for(int i=0;i<26;++i){
                temp[i]+=count[i];
            }
        }
        ans[node]=temp[labels[node]-'a'];
        return temp;
    }
    
    vector<int> countSubTrees(int n, vector<vector<int>>& edges, string labels) {
        vector<vector<int>> adj(n);
        for(auto& e:edges){
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }
        vector<int> ans(n,0);
        dfs(0,-1,adj,ans,labels);
        return ans;
    }
};