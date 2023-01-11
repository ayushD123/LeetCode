class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int n=heights.size();
        int m=heights[0].size();
        set<pair<int,pair<int,int>>> st;
        st.insert({0,{0,0}});
        vector<vector<int>> dist(n,vector<int> (m,1e9));
        dist[0][0]=0;
        while(!st.empty()){
            auto it=*(st.begin());
            st.erase(it);
            int row=it.second.first;
            int col=it.second.second;
            if(row==(n-1) && col==(m-1)){
                return dist[n-1][m-1];
            }
            int delR[]={-1,1,0,0};
            int delC[]={0,0,1,-1};
            for(int i=0;i<4;++i){
                int Nrow=row+delR[i];
                int Ncol=col+delC[i];
                if(Nrow>=0 && Ncol>=0 && Nrow<n && Ncol<m ){
                    int effort=max(abs(heights[Nrow][Ncol]-heights[row][col]),dist[row][col]);
                    if(effort<(dist[Nrow][Ncol])){
                        dist[Nrow][Ncol]=effort;
                    st.insert({dist[Nrow][Ncol],{Nrow,Ncol}});  
                    }
                  
                }
            }
        }
        return dist[n-1][m-1];
    }
};