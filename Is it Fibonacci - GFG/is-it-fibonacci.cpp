//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    long long solve(int N, int k, vector<long long> g) {
        // code here
        int i=0;
        int j=k-1;
        long long sum=0;
        for(int x=i;x<=j;++x){
            sum+=g[x];
        }
       // cout<<sum<<endl;
        int n=N;
        while(n--){
            g.push_back(sum);
            j++;
            
            sum=sum+g[j]-g[i];
            if(j==N-1){
                return g[j];
            }
          //  cout<<sum<<" ";
            i++;
        }
       
        long long ans=88;
        for(int x=0;x<g.size();++x){
            if(x==(N-1)){
                ans=g[x];
                break;
            }
        }
        return ans;
    }
};


//{ Driver Code Starts.

int main() {
    int T;
    cin >> T;
    while (T--) {
        int N, K;
        cin >> N >> K;

        vector<long long> GeekNum(K);

        for (int i = 0; i < K; i++) cin >> GeekNum[i];

        Solution ob;
        cout << ob.solve(N, K, GeekNum) << "\n";
    }
    return 0;
}

// } Driver Code Ends