//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
	public:
	//Function to find the shortest distance of all the vertices
    //from the source vertex S.
    vector <int> dijkstra(int n, vector<vector<int>> adj[], int src)
    {
        // Code here
        vector<int> dis(n,0);
        
       // int vis[n]={0};
      // int dis[n]={0};
        for(int i=0;i<n;++i){
            dis[i]=1e7+11;
        }
        dis[src]=0;
       // vector<int> adj[n];
        // for(int i=0;i<m;++i){
        //     adj[edges[i][0]].push_back(edges[i][1]);
        //      adj[edges[i][1]].push_back(edges[i][0]);
        // }
        queue<int> q;
        q.push(src);
        while(!q.empty()){
           // pair<int,int> p=q.front();
            int node=q.front();
            q.pop();
           // int dis=p.second;
            for(auto it:adj[node]){
                
                if(dis[it[0]]>dis[node]+it[1]){
                    dis[it[0]]=dis[node]+it[1];
                    q.push(it[0]);
                
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