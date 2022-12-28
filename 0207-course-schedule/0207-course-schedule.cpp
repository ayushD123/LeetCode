class Solution {
public:
    bool canFinish(int N, vector<vector<int>>& pre) {
        int V=N;
	      vector<int> ans;
	      vector<int> adj[N];
	      for(auto it:pre){
	          adj[it[0]].push_back(it[1]);
	      }
	   vector<int> inDeg(V,0);
	  for(int i=0;i<V;++i){
	      for(auto it:adj[i]){
	          inDeg[it]++;
	      }
	  }

	  
	   
	   queue<int> q;
	 for(int i=0;i<V;++i){
	     if(inDeg[i]==0){
	         q.push(i);
	      ;
	         ans.push_back(i);
	     }
	 }
	 
	 while(!q.empty()){
	     int node=q.front();
	     q.pop();
	     for(auto it:adj[node]){
	    
	             inDeg[it]--;
	             if(inDeg[it]==0){
	                 ans.push_back(it);
	                 q.push(it);
	           //  }
	         }
	     }
	     
	     
	 }
	 if(ans.size()!=V){
	     return 0;
	 }
	 return 1;
    
    }
};