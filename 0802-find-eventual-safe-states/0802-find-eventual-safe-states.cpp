class Solution {
    private:
     bool checkdfs(int node,vector<vector<int>>& adj,int vis[],int pathvis[]){
      vis[node] = 1;
      pathvis[node] = 1;
      
      for(auto neigh : adj[node]){
          if(!vis[neigh]){
              if(checkdfs(neigh,adj,vis,pathvis)){
                 //we are not back tracking the path array
                  return true;
              }
          }
          else if(pathvis[neigh]){
               //we are not back tracking the path array

              return true;
          }
      }
     
      // the cycle is not presant back track the path array
      pathvis[node] = 0;
      return false;
  }
    bool dfs(int node,vector<vector<int>>& graph,int vis[],int path[],vector<int> &ans){
        vis[node]=1;
        path[node]=1;
  //  ans.push_back(node);
        for(auto it:graph[node]){
            if(!vis[it]){
                if(dfs(it,graph,vis,path,ans)){
                    return true;
                }
            }else{
                if(path[it]==1){
                    return true;
                }
            }
        }
        
        path[node]=0;
        return false;
    }
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n=graph.size();
     int vis[100005]={0};
        int path[100005]={0};
        vector<int> ans;
        for(int i=0;i<n;i++){
            
            
                if(checkdfs(i,graph,vis,path)){
                    continue;
                }
                else{
                    ans.push_back(i);
                }
            
        }
       
        return ans;
    }
};