//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int countPaths(int n, vector<vector<int>>& roads) {
        // code here
        set<pair<int,int>> st;
        vector<pair<int,int>> adj[n];
        for(auto it:roads){
            adj[it[0]].push_back({it[1],it[2]});
            adj[it[1]].push_back({it[0],it[2]});
        }
        vector<int> dist(n,1e9);
        dist[0]=0;
        int mod=(int)(1e9+7);
        vector<int> ways(n,0);
        ways[0]=1;
        st.insert({0,0});
        while(!st.empty()){
            auto itt=*(st.begin());
            int dis=itt.first;
            int node=itt.second;
            st.erase(itt);
            for(auto it:adj[node]){
                int newNode=it.first;
                int nDis=it.second;
                if(dist[newNode]>(nDis+dis)){
                    dist[newNode]=(nDis+dis);
                    st.insert({nDis+dis,newNode});
                    
                    ways[newNode]=ways[node];
                    
                }else 
                if(dist[newNode]==(nDis+dis)){
                    ways[newNode]+=ways[node]%mod;
                }
            }
        }
        return ways[n-1]%mod;
    }
};

//{ Driver Code Starts.

int main() {
    int T;
    cin >> T;
    while (T--) {
        int n, m;
        cin >> n >> m;
        int u, v;

        vector<vector<int>> adj;

        for (int i = 0; i < m; ++i) {
            vector<int> temp;
            for (int j = 0; j < 3; ++j) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            adj.push_back(temp);
        }

        Solution obj;
        cout << obj.countPaths(n, adj) << "\n";
    }

    return 0;
}
// } Driver Code Ends