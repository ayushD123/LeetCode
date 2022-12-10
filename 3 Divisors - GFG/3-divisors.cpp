//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
class Solution
{
public:
    vector<int> threeDivisors(vector<long long> query, int q)
    {
        // Write your code here
        vector<int> ans;
       // int cnt=0;
        for(long long i=0;i<q;++i){
             long long n=query[i];
            long long cnt=0;
            // if(n<4){
            //     ans.push_back(0);
            //     continue;
            // }
            
            long long isprime[n]={0};
            isprime[0]=1;
            isprime[1]=1;
            for(long long i=2;i<=n;++i){
                if(!isprime[i]){
                    for(int j=i*2;j<=n;j+=i){
                        isprime[j]=1;
                    }
                }
            }
            for(long long i=2;i<n;++i){
                if(!isprime[i]){
                    if((i*i)<=n){
                        cnt++;
                    }
                }
            }
            ans.push_back(cnt);
            
        }
        return ans;
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while(t--){
        int q;cin>>q;
        vector<long long> query(q);
        for(int i=0;i<q;i++){
            cin>>query[i];
        }
        Solution ob;
            
        vector<int> ans = ob.threeDivisors(query,q);
        for(auto cnt : ans) {
            cout<< cnt << endl;
        }
    }
    return 0;
}
// } Driver Code Ends