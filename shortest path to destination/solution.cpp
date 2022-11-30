//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
    
   
  public:
    int shortestDistance(int N, int M, vector<vector<int>> A, int X, int Y) {
        // code here
        int cnt=0;
        queue<vector<int>> q;
       // vector<int> v;
     if(A[0][0]==0) return -1;
        q.push({0,0,0});
        while(!q.empty()){
            vector<int> p=q.front();
            q.pop();
            int row=p[0];
            int col=p[1];
            cnt=p[2];
            if(row==X && col==Y){
                return cnt;
            }
            
            int delrow[]={-1,1,0,0};
          int delcol[]={0,0,1,-1};
             for(int it=0;it<4;++it){
            int newrow=delrow[it]+row;
            int newcol=delcol[it]+col;
            if(newrow<0 || newcol<0 || newrow>=N || newcol>=M) continue;
            if(A[newrow][newcol]!=1) continue;
          //  vector<int> t;
            //cnt+=1;
            A[newrow][newcol]=99;
            // t.push_back(newrow);
          //  t.push_back(newcol);
            //t.push_back(cnt+1);
            q.push({newrow,newcol,cnt+1});
        }
       
    }
//     for(auto it:v){
//         cout<<it<<" ";
//     }
//  //   cout<<endl;
    
    // if(v.size()!=0){
    //     return *min_element(v.begin(),v.end());
    // }
    return -1;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, M, x, y;
        cin >> N >> M;
        vector<vector<int>> v(N, vector<int>(M));
        for (int i = 0; i < N; i++)
            for (int j = 0; j < M; j++) cin >> v[i][j];
        cin >> x >> y;
        Solution ob;
        cout << ob.shortestDistance(N, M, v, x, y) << "\n";
    }
}
// } Driver Code Ends