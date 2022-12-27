class Solution {
public:
    void dfs(int node,vector<int> &vis,vector<int> adj[]){
        vis[node]=1;
        for(auto it:adj[node]){
            if(vis[it]==0){
                dfs(it,vis,adj);
            }
        }
    }
    
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        vector<int> adj[rooms.size()];
        for(int i=0;i<rooms.size();++i){
            for(int j=0;j<rooms[i].size();++j){
                adj[i].push_back(rooms[i][j]);
            }
        }
        vector<int> vis(rooms.size(),0);
        dfs(0,vis,adj);
        for(auto it:vis){
            cout<<it<<" ";
            if(it==0){
                return false;
            }
        }
        return true;
    }
};