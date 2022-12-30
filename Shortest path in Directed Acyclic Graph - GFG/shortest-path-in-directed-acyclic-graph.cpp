//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
  void dfs(int node,stack<int> &st,int vis[],vector<pair<int,int>> adj[]){
      vis[node]=1;
      for(auto it:adj[node]){
          if(vis[it.first]==0){
              dfs(it.first,st,vis,adj);
          }
      }
      st.push(node);
  }
  
     vector<int> shortestPath(int N,int M, vector<vector<int>>& edges){
        // code here
        vector<pair<int,int>> adj[N];
        for(int i=0;i<M;++i){
            int a=edges[i][0];
            int b=edges[i][1];
            int wt=edges[i][2];
            adj[a].push_back({b,wt});
        }
        stack<int> st;
        int vis[N]={0};
        for(int i=0;i<N;++i){
            if(vis[i]==0){
                dfs(i,st,vis,adj);
            }
        }
        vector<int> dis(N,1e9+11);
        // for(int i=0;i<N;++i){
        //     dis[i]=ie9+11;
        // }
        dis[0]=0;
        while(!st.empty()){
            int node=st.top();
            st.pop();
            for(auto it:adj[node]){
                if((dis[node]+it.second)<dis[it.first]){
                    dis[it.first]=dis[node]+it.second;
                }
            }
        }
         for(int i=0;i<N;++i){
             if(dis[i]==1e9+11){
                 dis[i]=-1;
             }
         }
         return dis;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> edges;
        for(int i=0; i<m; ++i){
            vector<int> temp;
            for(int j=0; j<3; ++j){
                int x; cin>>x;
                temp.push_back(x);
            }
            edges.push_back(temp);
        }
        Solution obj;
        vector<int> res = obj.shortestPath(n, m, edges);
        for (auto x : res) {
            cout << x << " ";
        }
        cout << "\n";
    }
}

// } Driver Code Ends