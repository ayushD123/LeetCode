//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    int powerfullInteger(int n,vector<vector<int>> &intervals,int k){
        // Code here
        int maxx=0;
       for(auto it:intervals){
           maxx=max(maxx,it[1]);
       }
       vector<int> arr(maxx+2,0);
       for(auto it:intervals){
           arr[it[0]]++;
           arr[it[1]+1]--;
       }
       int ans=-1;
       for(int i=1;i<=maxx;++i){
           arr[i]=arr[i-1]+arr[i];
           if(arr[i]>=k){
               ans=max(ans,i);
           }
       }
       return ans;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n,k;
        cin>>n;
        vector<vector<int>> intervals(n,vector<int>(2));
        for(int i=0;i<n;i++){
            cin>>intervals[i][0]>>intervals[i][1];
        }
        cin>>k;
        Solution ob;
        cout<<ob.powerfullInteger(n,intervals,k)<<endl;
    }
    return 0;
}
// } Driver Code Ends