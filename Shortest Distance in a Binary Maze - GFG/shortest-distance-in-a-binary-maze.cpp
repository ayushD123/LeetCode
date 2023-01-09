//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int shortestPath(vector<vector<int>> &A, pair<int, int> source,
                     pair<int, int> destination) {
                         //USING SIMPLE BFS
        // code here
//          int cnt=0;
//         queue<vector<int>> q;
//         int X=destination.first;
//         int Y=destination.second;
//         int N=A.size();
//         int M=A[0].size();
//       // vector<int> v;
//     // if(A[0][0]==0) return -1;
//         q.push({source.first,source.second,0});
//         while(!q.empty()){
//             vector<int> p=q.front();
//             q.pop();
//             int row=p[0];
//             int col=p[1];
//             cnt=p[2];
//             if(row==X && col==Y){
//                 return cnt;
//             }
            
//             int delrow[]={-1,1,0,0};
//           int delcol[]={0,0,1,-1};
//              for(int it=0;it<4;++it){
//             int newrow=delrow[it]+row;
//             int newcol=delcol[it]+col;
//             if(newrow<0 || newcol<0 || newrow>=N || newcol>=M) continue;
//             if(A[newrow][newcol]!=1) continue;
//           //  vector<int> t;
//             //cnt+=1;
//             A[newrow][newcol]=99;
//             // t.push_back(newrow);
//           //  t.push_back(newcol);
//             //t.push_back(cnt+1);
//             q.push({newrow,newcol,cnt+1});
//         }
       
//     }
// //     for(auto it:v){
// //         cout<<it<<" ";
// //     }
// //  //   cout<<endl;
    
//     // if(v.size()!=0){
//     //     return *min_element(v.begin(),v.end());
//     // }
//     return -1;
                //USING DIJKSTRA
        int vis[A.size()][A[0].size()];
        for(int i=0;i<A.size();++i){
            for(int j=0;j<A[0].size();++j){
                vis[i][j]=1e7+10;
            }
        }
        set<pair<int,pair<int,int>>> st;
        int dr[]={-1,1,0,0};
          int dc[]={0,0,1,-1};
        st.insert({0,{source.first,source.second}});
        while(!st.empty()){
            auto it=*(st.begin());
            st.erase(it);
            int row=it.second.first;
            int col=it.second.second;
            int dis=it.first;
            if(row==destination.first && col==destination.second){
                return dis;
            }
            for(int i=0;i<4;++i){
                int delrow=row+dr[i];
                int delcol=col+dc[i];
                if(delrow>=A.size() || delrow<0 || delcol>=A[0].size() || delcol<0 || (vis[delrow][delcol]<=dis+1) || A[delrow][delcol]==0) continue;
                vis[delrow][delcol]=dis+1;
                st.insert({dis+1,{delrow,delcol}});
            }
            
        }
       return -1;
    }
};


//{ Driver Code Starts.
int main() {

    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> grid(n, vector<int>(m));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }

        pair<int, int> source, destination;
        cin >> source.first >> source.second;
        cin >> destination.first >> destination.second;
        Solution obj;
        cout << obj.shortestPath(grid, source, destination) << endl;
    }
}

// } Driver Code Ends