class Solution {
public:
     bool bfs(int node,int color[],vector<int>adj[]){
        color[node]=0;
        queue<int> q;
        q.push(node);
        while(!q.empty()){
            int par=q.front();
            q.pop();
            for(auto it:adj[par]){
                if(color[it]==-1){
                    color[it]=!color[par];
                    q.push(it);
                }else{
                    if(color[it]==color[par]){
                        return false;
                    }
                }
            }
        }
        return true;
    }
    bool dfs(int node,vector<int> adj[],vector<int> &col,int color){
        col[node]=color;
        for(auto it:adj[node]){
            if(col[it]==-1){
                if(!dfs(it,adj,col,!color)){
                    return false;
                }
            }else{
                if(col[it]==col[node]){
                    return false;
                }
            }
        }
        return true;
    }
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        if(n<=1){
            return true;
        }
        vector<int> adj[n+1];
        int color[n+1];
        // int col[n+1];
        // for(int i=0;i<=n;++i){
        //     col[i]=-1;
        // }
        for(int i=0;i<dislikes.size();++i){
        //    for(int j=0;j<2;++j){
                adj[dislikes[i][0]].push_back(dislikes[i][1]);
            adj[dislikes[i][1]].push_back(dislikes[i][0]);
         //   }
        }
        for(int i=1;i<=n;++i){
	        color[i]=-1;
	    }
	    for(int i=1;i<=n;++i){
	        if(color[i]==-1){
	           if(bfs(i,color,adj)==false){
	               return false;
	           }
	        }
	    }
	    return true;
	    
	}
};