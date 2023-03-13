//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
/*You are required to complete this function*/

class Solution{
    public:
    int maxLen(vector<int>&A, int n)
    {   
        // Your code here
        long long sum=0;
        unordered_map<long long,long long> mp;
        int ans=0;
        for(int i=0;i<n;++i){
            sum+=A[i];
            if(sum==0){
                ans=max(ans,i+1);
            }
            if(mp.find(sum)!=mp.end()){
                
                int j=mp[sum];
             //  cout<<i<<" "<<j<<endl;
                ans=max(ans,i-j);
            }else{
               // if(mp.find(sum)==mp.end())
                mp[sum]=i;
            }
        }
        if(sum==0){
            return n;
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