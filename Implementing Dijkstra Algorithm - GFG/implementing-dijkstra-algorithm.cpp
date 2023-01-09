//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
	public:
	//Function to find the shortest distance of all the vertices
    //from the source vertex S.
    vector <int> dijkstra(int V, vector<vector<int>> adj[], int src)
    {
        // Code here
         priority_queue<int,vector<int>,greater<int>> pq;
    //int dis[n]={0};
    vector<int> dis(V,1e7);
    // for(int i=0;i<n;++i){
    //     dis[i]=1e9+10;
    // }
    dis[src]=0;
    pq.push(src);
    while(!pq.empty()){
        int node=pq.top();
       
        pq.pop();
        for(auto it:adj[node]){
            int adjV=it[0];
            int weight=it[1];
            if(dis[node]+weight<dis[adjV]){
                dis[adjV]=dis[node]+weight;
                pq.push(adjV);
            }
        }
    }
    return dis;
    
    }
};


//{ Driver Code Starts.


int main()
{
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> adj[V];
        int i=0;
        while (i++<E) {
            int u, v, w;
            cin >> u >> v >> w;
            vector<int> t1,t2;
            t1.push_back(v);
            t1.push_back(w);
            adj[u].push_back(t1);
            t2.push_back(u);
            t2.push_back(w);
            adj[v].push_back(t2);
        }
        int S;
        cin>>S;
        
        Solution obj;
    	vector<int> res = obj.dijkstra(V, adj, S);
    	
    	for(int i=0; i<V; i++)
    	    cout<<res[i]<<" ";
    	cout<<endl;
    }

    return 0;
}


// } Driver Code Ends