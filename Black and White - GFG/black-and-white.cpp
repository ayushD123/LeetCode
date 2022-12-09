//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

long long numOfWays(int n, int m);

int main() {
    // code
    int T;
    cin >> T;
    while (T--) {
        int n, m;
        cin >> n >> m;
        cout << numOfWays(n, m) << endl;
    }
    return 0;
}
// } Driver Code Ends


//Function to find out the number of ways we can place a black and a 
//white Knight on this chessboard such that they cannot attack each other.

int isSafe(int row,int col,int n,int m){
    int cnt=0;
    int delrow[]={ -2, -1, 1, 2, -2, -1, 1, 2 };
    int delcol[]={ -1, -2, -2, -1, 1, 2, 2, 1 };
    for(int i=0;i<8;++i){
        int nrow=delrow[i]+row;
        int ncol=delcol[i]+col;
        if(nrow>=0 && nrow<n && ncol>=0 && ncol<m){
            cnt++;
        }
    }
    return cnt;
}

long long numOfWays(int n, int m)
{
    // write code 
    long mod=1000000007;
         long long ans=0;
        for(int i=0;i<n;++i){
            for(int j=0;j<m;++j){
                int val=isSafe(i,j,n,m);
                ans+=((m*n)-1-val)%mod;
            }
        }
        return ans%mod;
}