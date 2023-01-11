class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        set<pair<int,pair<int,int>>> st;
        st.insert({0,{src,0}});
        vector<pair<int,int>> adj[n];
        for(int i=0;i<flights.size();++i){
            adj[flights[i][0]].push_back({flights[i][1],flights[i][2]});
            
       }
        vector<int> dist(n,1e7+10);
        dist[src]=0;
       while(!st.empty()){
           auto it=*(st.begin());
           st.erase(it);
           int node=it.second.first;
           int cost=it.second.second;
           int stops=it.first;
           if(stops>=(k+1)) continue;
           for(auto it:adj[node]){
               int weight=it.second;
               int Nnode=it.first;
               
               if(dist[Nnode]>(weight+dist[node])){
                   dist[Nnode]=weight+cost;
                   st.insert({stops+1,{Nnode,dist[Nnode]}});
               }
           }
       } 
        if(dist[dst]==(1e7+10)) return -1;
        return dist[dst];
    }
};