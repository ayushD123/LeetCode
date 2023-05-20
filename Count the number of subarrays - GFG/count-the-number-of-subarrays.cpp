//{ Driver Code Starts
//Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++
class Solution {
  public:
  
long long atmost(vector<int> &v,long long x,int n){
    int left=0;
    long long sum=0;
    int ans=0;
    long long cnt=0;
    int right=0;
  
    while(right<n){
        sum+=v[right];
        while(sum>x && left<n){
            sum-=v[left];
            left++;
        }
        cnt+=right-left+1;
        right++;
    }
    return cnt;
}
    long long countSubarray(int n,vector<int> v,long long l,long long r) {
      long long ans1=atmost(v,r,n);
   long long ans2=atmost(v,l-1,n);
   return (ans1-ans2);
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        long long L,R;
        cin>>N>>L>>R;
        vector<int> A(N);
        for(int i=0;i<N;i++){
            cin>>A[i];
        }
        Solution obj;
        auto ans = obj.countSubarray(N,A,L,R);
        cout<<ans<<endl;
    }
}  
// } Driver Code Ends