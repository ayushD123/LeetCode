//{ Driver Code Starts
//Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++
class Solution{
public:
    vector<long long> smallerSum(int n,vector<int> &arr){
        // Code here
        vector<long long > ans;
        unordered_map<int,long long> mp;
        vector<int> tmp=arr;
        sort(tmp.begin(),tmp.end());
        vector<long long > pre(n,0);
        pre[0]=0;
        mp[tmp[0]]=0;
        for(int i=1;i<n;++i){
            pre[i]=pre[i-1]+tmp[i-1];
            if(tmp[i]==tmp[i-1]){
                continue;
            }
            mp[tmp[i]]=pre[i];
        }
        
        
        // for(int i=1;i<n;++i){
            
        // }
        for(auto it:arr){
            ans.push_back(mp[it]);
        }
        return ans;
    }
    
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> arr(n);
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        Solution ob; 
        vector<long long> ans=ob.smallerSum(n,arr);
        for(int i=0;i<n;i++){
            if(i!=n-1){
                cout<<ans[i]<<" ";
            }
            else{
                cout<<ans[i]<<endl;
            }
        }
    }
    return 0;
}
// } Driver Code Ends