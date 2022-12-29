//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++
class Solution {
//   public:
//   bool checkdfs(int node,vector<int> adj[],int vis[],int pathvis[]){
//       vis[node] = 1;
//       pathvis[node] = 1;
//      // temp.push_back(node);
//       for(auto neigh : adj[node]){
//           if(!vis[neigh]){
//               if(checkdfs(neigh,adj,vis,pathvis)){
//                  //we are not back tracking the path array
//                   return true;
//               }
//           }
//           else if(pathvis[neigh]){
//               //we are not back tracking the path array

//               return true;
//           }
//       }
     
//       // the cycle is not presant back track the path array
//       pathvis[node] = 0;
//       return false;
//   }
//     vector<int> eventualSafeNodes(int V, vector<int> adj[]) {
//         // code here
//         int vis[V] ={0};
//         int pathvis[V] = {0};
        
//         vector<int> ans;
//         for(int i=0;i<V;i++){
            
            
//                 if(checkdfs(i,adj,vis,pathvis)){
//                     continue;
//                 }
//                 else{
//                     ans.push_back(i);
//                 }
            
//         }
       
//         return ans;
//     }
public:
vector<int> eventualSafeNodes(int V, vector<int> adj[]) {
        // code here
        vector<int> revAdj[V];
        vector<int> ans;
        int indeg[V]={0};
        for(int i=0;i<V;++i){
            for(auto it:adj[i]){
                revAdj[it].push_back(i);
                indeg[i]++;
            }
        }
        queue<int> q;
        for(int i=0;i<V;++i){
            if(indeg[i]==0){
                q.push(i);
            }
        }
        while(!q.empty()){
            int node=q.front();
            q.pop();
          //  if(indeg[node]==0){
                ans.push_back(node);
           // }
            for(auto it:revAdj[node]){
                indeg[it]--;
                if(indeg[it]==0){
                 //   ans.push_back(it);
                    q.push(it);
                }
            }
        }(
        sort(ans.begin(),ans.end()));
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