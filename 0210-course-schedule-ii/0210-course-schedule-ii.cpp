class Solution {
public:
    vector<int> findOrder(int n, vector<vector<int>>& pre) {
        vector<int> ans;
         int V=n;
         vector<int> adj[n];
	   vector<int> inDeg(V,0);
	  for(auto it:pre){
	      adj[it[1]].push_back(it[0]);
	  }
	   for(int i=0;i<V;++i){
	      for(auto it:adj[i]){
	          inDeg[it]++;
	      }
	  }
// 	  for(int i=0;i<V;++i){
// 	      cout<<i<<"->"<<inDeg[i]<<endl;
// 	  }
	  
	   
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
	      //   cout<<node<<"->"<<it<<endl;
	     //    if(inDeg[it]>0){
	            
	             inDeg[it]--;
	             if(inDeg[it]==0){
	                 ans.push_back(it);
	                 q.push(it);
	           //  }
	         }
	     }
	     
	     
	 }
	 if(ans.size()==n)
	 return ans;
	 return {};
    }
};