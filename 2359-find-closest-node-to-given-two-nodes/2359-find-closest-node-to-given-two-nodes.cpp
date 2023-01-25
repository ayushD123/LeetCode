class Solution {
public:
    void dfs(int node,vector<int> &edges,vector<int> &dist,vector<int> &vis){

        vis[node]=1;
        int neigh=edges[node];
        if(neigh!=-1 && vis[neigh]==0){
            dist[neigh]=dist[node]+1;
            dfs(neigh,edges,dist,vis);
        }
    }
    int closestMeetingNode(vector<int>& edges, int node1, int node2) {
        int n=edges.size();
        vector<int> dist1(n,1e5+10);
        vector<int> dist2(n,1e5+10);
        vector<int> vis1(n,0);
        vector<int> vis2(n,0);
        dist1[node1]=0;
        dist2[node2]=0;
        dfs(node1,edges,dist1,vis1);
        dfs(node2,edges,dist2,vis2);
       
        int ans=1e5+10;
        int anss=-1;
        for(int i=0;i<n;++i){
            int a=max(dist1[i],dist2[i]);
            if(a<ans){
                ans=a;
                anss=i;
            }
        }
      
      
        return anss;
    }
};