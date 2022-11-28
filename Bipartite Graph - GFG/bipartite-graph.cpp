/*
Bipartite-those graphs who can be colored with 2 colors suh that no two adjacent nodes have same color
also bipartite graph have only even cycle or no cycle(thats why pure concept of cycle detection doesnt work need to modify a little bit)
*/

//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
    private:
    
    bool bfs(int node,int color[],int V,vector<int>adj[]){
        color[node]=0;
        queue<int> q;
        q.push(node);
        while(!q.empty()){
            int par=q.front();
            q.pop();
            for(auto it:adj[par]){
		    // if the adjacent node is yet not colored
	            // you will give the opposite color of the node 
                if(color[it]==-1){
                    color[it]=!color[par];
                    q.push(it);
                }else{
			// is the adjacent guy having the same color 
	            // someone did color it on some other path 
                    if(color[it]==color[par]){
                        return false;
                    }
                }
            }
        }
        return true;
    }
    
    
public:
	bool isBipartite(int V, vector<int>adj[]){
	    // Code here
	    int color[V];
	    for(int i=0;i<V;++i){
	        color[i]=-1;
	    }
	    for(int i=0;i<V;++i){
	        if(color[i]==-1){
	           if(bfs(i,color,V,adj)==false){
	               return false;
	           }
	        }
	    }
	    return true;
	    
	}

};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int V, E;
		cin >> V >> E;
		vector<int>adj[V];
		for(int i = 0; i < E; i++){
			int u, v;
			cin >> u >> v;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
		Solution obj;
		bool ans = obj.isBipartite(V, adj);    
		if(ans)cout << "1\n";
		else cout << "0\n";  
	}
	return 0;
}
// } Driver Code Ends
