//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
/*You are required to complete this function*/

class Solution{
    public:
    int maxLen(vector<int>&arr, int n)
    {   
        // Your code here
        unordered_map<int,int> mp;
        int pre=0;
        int ans=0;
        for(int i=0;i<n;++i){
            pre+=arr[i];
            if(pre==0){
                ans=i+1;
            }
            if(mp.find(pre)!=mp.end()){
                int j=mp[pre];
                ans=max(ans,i-j);
                
            }else{
                mp[pre]=i;
            }
        }
        return ans;
    }
};


//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int m;
        cin>>m;
        vector<int> array1(m);
        for (int i = 0; i < m; ++i){
            cin>>array1[i];
        }
        Solution ob;
        cout<<ob.maxLen(array1,m)<<endl;
    }
    return 0; 
}



// } Driver Code Ends