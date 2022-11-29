//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
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


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {

        int V, E;
        cin >> V >> E;
        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        vector<int> safeNodes = obj.eventualSafeNodes(V, adj);
        for (auto i : safeNodes) {
            cout << i << " ";
        }
        cout << endl;
    }
}

// } Driver Code Ends