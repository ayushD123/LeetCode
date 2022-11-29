class Solution {
  public:
  bool checkdfs(int node,vector<int> adj[],int vis[],int pathvis[],vector<int> &temp){
      vis[node] = 1;
      pathvis[node] = 1;
      temp.push_back(node);
      for(auto neigh : adj[node]){
          if(!vis[neigh]){
              if(checkdfs(neigh,adj,vis,pathvis,temp)){
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
    vector<int> eventualSafeNodes(int V, vector<int> adj[]) {
        // code here
        int vis[V] ={0};
        int pathvis[V] = {0};
        set<int >s;
        vector<int> ans;
        for(int i=0;i<V;i++){
            vector<int> temp;
            
                if(checkdfs(i,adj,vis,pathvis,temp)){
                    continue;
                }
                else{
                    ans.push_back(i);
                }
            
        }
       
        return ans;
    }
};
