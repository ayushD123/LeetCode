//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
    public:
    bool wifiRange(int N, string S, int X){
        // code here
        vector<int> vis(N,0);
        for(int i=0;i<N;++i){
            if(S[i]=='1'){
                int k=X;
                int j=i;
                
                while(j<N && k>=0){
                    vis[j]=1;
                    k--;
                    j++;
                }
            }
        }
         for(int i=N-1;i>=0;i--){
            if(S[i]=='1'){
                int k=X;
                int j=i;
                
                while(j>=0 && k>=0){
                    vis[j]=1;
                    k--;
                    j--;
                }
            }
        }
        int cnt=0;
        for(auto it:vis){
            if(it==0){
                return false;
            }
        }
        return true;
    }
};

//{ Driver Code Starts.

int main(){
    int T;
    cin >> T;
    while(T--){
        int N, X;
        string S;
        cin >> N >> X >> S;
        Solution obj;
        cout << obj.wifiRange(N, S, X) << "\n";
    }
}

// } Driver Code Ends