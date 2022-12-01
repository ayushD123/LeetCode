class Solution {
    private:
    void dfs(int node,int vis[],vector<vector<int>> graph,vector<vector<int>> &ans,vector<int> temp){
        vis[node]=1;
        int n=graph.size();
        temp.push_back(node);
        if(node==(n-1)){
            ans.push_back(temp);
            temp.clear();
            return;
        }
        for(auto it:graph[node]){
           // if(!vis[it]){
                dfs(it,vis,graph,ans,temp);
          //  }
        }
    }
public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        int n=graph.size();
        int m=graph[0].size();
        vector<int> temp;
        int vis[100]={0};
        vector<vector<int>> ans;
      //  vector<vector<int>> vis(n,vector<int> (m,0));
        dfs(0,vis,graph,ans,temp);
        return ans;
    }
};