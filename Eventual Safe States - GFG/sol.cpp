// User function Template for C++

class Solution {
    private:
    bool dfs(int src,vector<int> adj[],int vis[],int path[],int check[]){
        vis[src]=1;
        path[src]=1;
       // check[src]=0;
        for(auto node:adj[src]){
            if(!vis[node]){
               if (dfs(node,adj,vis,path,check)){
                  // check[src]=0;
                 return true;
             }
            }else{
                if(path[node]==1){
                   // check[src]=0;
                    return true;
                }
            }
            //path[node]=0;
        }
        check[src]=1;
        path[src]=0;
        return false;
        //.push_back(src);
        
    }
  public:
    vector<int> eventualSafeNodes(int V, vector<int> adj[]) {
        // code here
        vector<int> ans;
        int vis[V]={0};
        int check[V]={0};
        int path[V]={0};
        for(int i=0;i<V;++i){
            if(!vis[i]){
               dfs(i,adj,vis,path,check);
                   
               
            }
            
        }
        for(int i=0;i<V;++i){
            if(check[i]){
                ans.push_back(i);
            }
        }
        return ans;
    }
};
