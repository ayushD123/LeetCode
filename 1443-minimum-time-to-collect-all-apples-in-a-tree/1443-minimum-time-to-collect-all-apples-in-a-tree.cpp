class Solution {
public:
    int dfs(int node, int parent, vector<vector<int>>& adj, vector<bool>& hasApple,int vis[]) {
        int totalTime = 0, childTime = 0;
        vis[node]=1;
        for (auto child : adj[node]) {
            if (vis[child]) continue;
            vis[child]=1;
            childTime = dfs(child, node, adj, hasApple,vis);
            // childTime > 0 indicates subtree of child has apples. Since the root node of the
            // subtree does not contribute to the time, even if it has an apple, we have to check it
            // independently.
            if (childTime || hasApple[child]) totalTime += childTime + 2;
        }

        return totalTime;
    }

    int minTime(int n, vector<vector<int>>& edges, vector<bool>& hasApple) {
        vector<vector<int>> adj(n);
        int vis[n];
        for(int i=0;i<n;++i){
            vis[i]=0;
        }
        for (auto& edge : edges) {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }
        return dfs(0, -1, adj, hasApple,vis);
    }
};