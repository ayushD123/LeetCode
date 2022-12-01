class Solution {
    private:
    void dfs(int node,int vis[], vector<int> adj[]){
        vis[node]=1;
        for(auto it:adj[node]){
            if(vis[it]==0){
                dfs(it,vis,adj);
            }
        }
    }
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        vector<int> adj[300];
        int n=isConnected.size();
        for(int i=0;i<n;++i){
            for(int j=0;j<n;++j){
                if(isConnected[i][j]==1){
                    adj[i].push_back(j);
                     adj[j].push_back(i);
                }
            }
        }
        int cnt=0;
        int vis[300]={0};
        for(int i=0;i<n;++i){
           if(vis[i]==0){
               dfs(i,vis,adj);
               cnt++;
            }
        }
            return cnt;
    }
};