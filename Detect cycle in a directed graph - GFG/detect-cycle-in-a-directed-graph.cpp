//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    // Function to detect cycle in a directed graph.
    //using DFS
    /*
    private:
    bool dfs(int src,vector<int> adj[],int vis[],int path[]){
        vis[src]=1;
        path[src]=1;
        for(auto node:adj[src]){
            if(!vis[node]){
               if(dfs(node,adj,vis,path)){
                 return true;
             }
            }else{
                if(path[node]==1){
                    return true;
                }
            }
           
        }
        path[src]=0;
       return false;
    }
  public:
    // Function to detect cycle in a directed graph.
    bool isCyclic(int V, vector<int> adj[]) {
        int vis[V]={0};
        int path[V]={0};
        for(int i=0;i<V;++i){
            if(!vis[i]){
               if(dfs(i,adj,vis,path)==true){
                   return true;
               }
            }
        }
        return false;
    }
    */
    //USING BFS(TOPOLOGICAL SORT->KAHN)
    public:
    /*
    Intiuation: since topological osrt only works for directed acyclic(without cycle) graph ,
    so when we try to apply iy we wont get ans of same length
    so if ans is not correct then there must exixst a graph because algo didnt worked properly
    */
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
