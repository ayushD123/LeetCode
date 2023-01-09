//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
	public:
	//Function to find the shortest distance of all the vertices
    //from the source vertex S.
    //Using PQ
    
    // vector <int> dijkstra(int V, vector<vector<int>> adj[], int src)
    // {
    //     // Code here
    //      priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
    // //int dis[n]={0};
    // vector<int> dis(V,1e7);
    // // for(int i=0;i<n;++i){
    // //     dis[i]=1e9+10;
    // // }
    // dis[src]=0;
    // pq.push({0,src});
    // while(!pq.empty()){
    //     int node=pq.top().second;
    //     int edgew=pq.top().first;
    //     pq.pop();
    //     for(auto it:adj[node]){
    //         int adjV=it[0];
    //         int weight=it[1];
    //         if(edgew+weight<dis[adjV]){
    //             dis[adjV]=edgew+weight;
    //             pq.push({dis[adjV],adjV});
    //         }
    //     }
    // }
    // return dis;
    
    //USING SET
    vector <int> dijkstra(int V, vector<vector<int>> adj[], int src)
    {
        set<pair<int,int>> st;
        vector<int> dis(V,1e7+10);
        dis[src]=0;
       
        st.insert({0,src});
        while(st.size()!=0){
            auto first=*(st.begin());//first element of set is always smallest st.begin returns iterator
            int node=first.second;
            int weight=first.first;
             st.erase(first);
            for(auto it:adj[node]){
                int adjN=it[0];
                int adjW=it[1];
                if(dis[adjN]>(adjW+weight)){
                    dis[adjN]=adjW+weight;
                    st.insert({dis[adjN],adjN});
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