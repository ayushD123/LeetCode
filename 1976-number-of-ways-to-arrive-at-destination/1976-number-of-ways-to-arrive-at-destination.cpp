class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
         set<pair<long long,long long>> st;
        vector<pair<long long,long long>> adj[n];
        for(auto it:roads){
            adj[it[0]].push_back({it[1],it[2]});
            adj[it[1]].push_back({it[0],it[2]});
        }
        vector<long long> dist(n,1e18);
        dist[0]=0;
        int mod=(int)(1e9+7);
        vector<long long> ways(n,0);
        ways[0]=1;
        st.insert({0,0});
        while(!st.empty()){
            auto itt=*(st.begin());
            long long dis=itt.first;
            int node=itt.second;
            st.erase(itt);
            for(auto it:adj[node]){
                int newNode=it.first;
                long long nDis=it.second;
                if(dist[newNode]>(nDis+dis)){
                    dist[newNode]=(nDis+dis);
                    st.insert({nDis+dis,newNode});
                    
                    ways[newNode]=ways[node];
                    
                }else 
                if(dist[newNode]==(nDis+dis)){
                    ways[newNode]+=ways[node]%mod;
                }
            }
        }
        return ways[n-1]%mod;
    }
};