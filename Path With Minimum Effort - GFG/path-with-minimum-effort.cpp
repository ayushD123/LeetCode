//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    int MinimumEffort(vector<vector<int>>& heights) {
        // Code here
        int n=heights.size();
        int m=heights[0].size();
        //vector<pair<int,pair<int,int>> adj[]
        set<pair<int,pair<int,int>>> st;
        st.insert({0,{0,0}});
        int dist[n][m];
        for(int i=0;i<n;++i){
            for(int j=0;j<m;++j){
                dist[i][j]=1e7+10;
            }
        }
        dist[0][0]=0;
        while(!st.empty()){
            auto it=*(st.begin());
            int dis=it.first;
            int row=it.second.first;
            int col=it.second.second;
             if(row==(n-1) && col==(m-1)){
                 return dis;
             }
            st.erase(it);
            int delrow[]={-1,0,1,0};
            int delcol[]={0,1,0,-1};
            for(int i=0;i<4;++i){
                int Nrow=row+delrow[i];
                int Ncol=col+delcol[i];
                if(Nrow>=0 && Nrow<n && Ncol>=0 && Ncol<m ){
                    int effort=max(abs(heights[Nrow][Ncol]-heights[row][col]),dist[row][col]);
                    if(effort<dist[Nrow][Ncol]){
                        dist[Nrow][Ncol]=effort;
                        st.insert({effort,{Nrow,Ncol}});
                    }
                
            }
        }
        }
        //  for(int i=0;i<n;++i){
        //     for(int j=0;j<m;++j){
        //         cout<<vis[i][j]<<" ";
        //     }
        //     cout<<endl;
        // }
        // return vis[n-1][m-1];
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n,m; cin>>n>>m;
        vector<vector<int>> heights;
       
        for(int i=0; i<n; ++i){
            vector<int> temp;
            for(int j=0; j<m; ++j){
                int x; cin>>x;
                temp.push_back(x);
            }
            heights.push_back(temp);
        }
       
        Solution obj;
        cout<<obj.MinimumEffort(heights)<<"\n";
    }
    return 0;
}
// } Driver Code Ends