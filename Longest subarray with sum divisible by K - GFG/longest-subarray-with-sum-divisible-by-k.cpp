//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends
//User function template for C++
class Solution{
public:	
	int longSubarrWthSumDivByK(int arr[], int n, int k)
	{
	    // Complete the function
	    //int rem=0;
	    int ans=0;
	    int pre=0;
	    unordered_map<int,int> mp;
	    mp[0]=-1;
	    for(int i=0;i<n;++i){
	        pre+=arr[i];
	       // if(pre%k==0){
	       //     ans=max(ans,i+1);
	            
	       // }
	       int rem=((pre%k)+k)%k;
	        if(mp.find(rem)!=mp.end()){
	            int j=mp[rem];
	            ans=max(ans,i-j);
	        }else{
	            mp[rem]=i;
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
	int n,k,i;
	cin>>n>>k; int arr[n];
	for(i=0;i<n;i++)
	cin>>arr[i];
	Solution ob;
	cout<<ob.longSubarrWthSumDivByK(arr, n, k)<<"\n";
	}
	return 0;	 
}

// } Driver Code Ends