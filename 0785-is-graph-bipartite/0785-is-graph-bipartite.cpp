class Solution {
    private:
    bool bfs(int node,int color[],int V,vector<vector<int>>& adj){
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
        return true;//should check all the condition(nodes) to arrive at conclusion that graph is bipartitie
    }
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int V=graph.size();
        
     int color[V];
	    for(int i=0;i<V;++i){
	        color[i]=-1;
	    }
	    for(int i=0;i<V;++i){
	        if(color[i]==-1){
	           if(bfs(i,color,V,graph)==false){
	               return false;
	           }
	        }
	    }
	    return true;
	    
	}
};
