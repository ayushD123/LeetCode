//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

    class Solution {
    
    private:
     bool dfs(int src,int vis[],vector<int> adj[],int par){
        vis[src]=1;
        for(auto node:adj[src]){
            
           if(vis[node]==0){
               if(dfs(node,vis,adj,src)){
                   return true;
               }
           }else if(node==src){
               return true;
           }
        }
        return false;
    }
  public:
    // Function to detect cycle in a directed graph.
    bool isCyclic(int V, vector<int> adj[]) {
       vector<int> ans;
	   vector<int> inDeg(V,0);
	  for(int i=0;i<V;++i){
	      for(auto it:adj[i]){
	          inDeg[it]++;
	      }
	  }

	  
	   
	   queue<int> q;
	 for(int i=0;i<V;++i){
	     if(inDeg[i]==0){
	         q.push(i);
	      ;
	         ans.push_back(i);
	     }
	 }
	 
	 while(!q.empty()){
	     int node=q.front();
	     q.pop();
	     for(auto it:adj[node]){
	    
	             inDeg[it]--;
	             if(inDeg[it]==0){
	                 ans.push_back(it);
	                 q.push(it);
	           //  }
	         }
	     }
	     
	     
	 }
	 if(ans.size()!=V){
	     return 1;
	 }
	 return 0;
    
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
        cout << obj.isCyclic(V, adj) << "\n";
    }

    return 0;
}

// } Driver Code Ends