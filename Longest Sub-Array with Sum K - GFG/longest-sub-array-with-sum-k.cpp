//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
    public:
    int lenOfLongSubarr(int arr[],  int N, int K) 
    { 
        // Complete the function
        unordered_map<int,int> mp;
        int pre=0;
        int ans=0;
        for(int i=0;i<N;++i){
            pre+=arr[i];
            if(pre==K){
                ans=max(ans,i+1);
            
            }
            if(mp.find(pre-K)!=mp.end()){
                int j=mp[pre-K];
                ans=max(ans,i-j);
            }
            
             if(mp.find(pre)==mp.end())
             mp[pre]=i;
                
            
        }
        return ans;
    } 

};

//{ Driver Code Starts.

int main() {
	//code
	
	int t;cin>>t;
	while(t--)
	{
	    int n, k;
	    cin>> n >> k;
	    int a[n];
	    
	    for(int i=0;i<n;i++)
	        cin>>a[i];
	   Solution ob;
	   cout << ob.lenOfLongSubarr(a, n , k)<< endl;
	    
	}
	
	return 0;
}
// } Driver Code Ends