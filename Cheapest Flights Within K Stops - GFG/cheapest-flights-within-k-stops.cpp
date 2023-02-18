//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    int CheapestFLight(int n, vector<vector<int>>& flights, int src, int dst, int K)  {
        // Code here
        set<pair<int,pair<int,int>>> st;//{stops,{node,dist}}
        st.insert({0,{src,0}});
        vector<pair<int,int>> adj[n];
        for(int i=0;i<flights.size();++i){
            adj[flights[i][0]].push_back({flights[i][1],flights[i][2]});
        }
        // for(int i=0;i<flights.size();++i){
        //     vector<pair<int,int>> v=adj[i];
        //     cout<<i<<"->";
        //     for(auto it:v){
        //         cout<<it.first<<" ";
        //     }
        //     cout<<endl;
        // }
        vector<int> dist(n,1e7+10);
        dist[src]=0;
        while(!st.empty()){
            auto it=*(st.begin());
            int stops=it.first;
            int node=it.second.first;
            int cost=it.second.second;
            st.erase(it);
           if(stops>=(K+1)) continue;
            for(auto it:adj[node]){
                int newNode=it.first;
                int weight=it.second;
                if(dist[newNode]>(weight+cost)){
                     dist[newNode]=weight+cost;
                    st.insert({stops+1,{newNode,dist[newNode]}});
                }
               
            }
        }
        if(dist[dst]==(1e7+10)) return -1;
        return dist[dst];
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n; cin>>n;
        int edge; cin>>edge;
        vector<vector<int>> flights;
        
        for(int i=0; i<edge; ++i){
            vector<int> temp;
            for(int j=0; j<3; ++j){
                int x; cin>>x;
                temp.push_back(x);
            }
            flights.push_back(temp);
        }
        
        int src,dst,k;
        cin>>src>>dst>>k;
        Solution obj;
        cout<<obj.CheapestFLight(n,flights,src,dst,k)<<"\n";
    }
    return 0;
}
// } Driver Code Ends