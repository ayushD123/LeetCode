//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
    private:
    void dfs(int node,int vis[],vector<int> adj[]){
        vis[node]=1;
        for(auto it:adj[node]){
            if(vis[it]==0){
                dfs(it,vis,adj);
            }
        }
    }
  public:
    int numProvinces(vector<vector<int>> adj, int V) {
        // code here[]
        int ans=0;
        int vis[V]={0};
        vector<int> adjL[V];
        for(int i=0;i<V;++i){
            for(int j=0;j<V;++j){
                if(adj[i][j]==1 && i!=j){
                    adjL[i].push_back(j);
                   // adjL[j].push_back(i);
                }
            }
        }
        for(int i=0;i<V;++i){
            if(vis[i]==0){
                ans++;
                dfs(i,vis,adjL);
               // ans++;
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
        int V,x;
        cin>>V;
        
        vector<vector<int>> adj;
        
        for(int i=0; i<V; i++)
        {
            vector<int> temp;
            for(int j=0; j<V; j++)
            {
                cin>>x;
                temp.push_back(x);
            }
            adj.push_back(temp);
        }
        

        Solution ob;
        cout << ob.numProvinces(adj,V) << endl;
    }
    return 0;
}
// } Driver Code Ends