//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
  
    vector<int> shortestPath(vector<vector<int>>& edges, int n,int m, int src){
        // code here
        //vector<vector<int>> edges
        vector<int> dis(n,0);
       // int vis[n]={0};
      // int dis[n]={0};
        for(int i=0;i<n;++i){
            dis[i]=1e7+11;
        }
        dis[src]=0;
        vector<int> adj[n];
        for(int i=0;i<m;++i){
            adj[edges[i][0]].push_back(edges[i][1]);
             adj[edges[i][1]].push_back(edges[i][0]);
        }
        queue<int> q;
        q.push(src);
        while(!q.empty()){
           // pair<int,int> p=q.front();
            int node=q.front();
            q.pop();
           // int dis=p.second;
            for(auto it:adj[node]){
                
                if(dis[it]>dis[node]+1){
                    dis[it]=dis[node]+1;
                    q.push(it);
                }
            }
        }
        for(int i=0;i<n;++i){
            if(dis[i]==1e7+11){
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
        int n, m; cin >> n >> m;
        vector<vector<int>> edges;

        for (int i = 0; i < m; ++i) {
            vector<int> temp;
            for(int j=0; j<2; ++j){
                int x; cin>>x;
                temp.push_back(x);
            }
            edges.push_back(temp);
        }

        int src; cin >> src;

        Solution obj;

        vector<int> res = obj.shortestPath(edges, n, m, src);

        for (auto x : res){
            cout<<x<<" ";
        }
        cout << "\n";
    }
}

// } Driver Code Ends