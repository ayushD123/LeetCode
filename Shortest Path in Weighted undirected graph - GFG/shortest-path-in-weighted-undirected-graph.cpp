//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    vector<int> shortestPath(int n, int m, vector<vector<int>>& edges) {
        // Code here
         set<pair<int,int>> st;
        vector<int> dis(n+1,1e7+10);
        dis[1]=0;
        int parent[n+1]={0};
        vector<pair<int,int>> adj[n+1];
        for(int i=0;i<m;++i){
            adj[edges[i][0]].push_back({edges[i][1],edges[i][2]});
            adj[edges[i][1]].push_back({edges[i][0],edges[i][2]});
        }
        parent[1]=1;
       
        st.insert({0,1});
        while(st.size()!=0){
            auto first=*(st.begin());//first element of set is always smallest st.begin returns iterator
            int node=first.second;
            int weight=first.first;
             st.erase(first);
            for(auto it:adj[node]){
                int adjN=it.first;
                int adjW=it.second;
                if(dis[adjN]>(adjW+weight)){
                    dis[adjN]=adjW+weight; //weight==dis[node]
                    parent[adjN]=node;
                    st.insert({dis[adjN],adjN});
                }
            }
        }
        vector<int> ans;
        int par=n;
        while(par!=parent[par]){
            ans.push_back(par);
            par=parent[par];
        }
        ans.push_back(1);
       if(parent[par]==0){
           return {-1};
       }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    // your code goes here
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> edges;
        for (int i = 0; i < m; ++i) {
            vector<int> temp;
            for (int j = 0; j < 3; ++j) {
                int x;
                cin >> x;
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