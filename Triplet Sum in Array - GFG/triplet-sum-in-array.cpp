//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
    public:
    //Function to find if there exists a triplet in the 
    //array A[] which sums up to X.
    bool find3Numbers(int arr[], int n, int X)
    {
        for(int i=0;i<n;++i){
             unordered_map<int,int> mp;
             int two_sum=X-arr[i];
             for(int j=i+1;j<n;++j){
                 if(mp.find(two_sum-arr[j])!=mp.end()){
                     return 1;
                 }
                 mp[arr[j]]++;
                 
             }
        }
        return 0;
      
       
    }

};

//{ Driver Code Starts.

int main()
{
	int T;
	cin>>T;
	while(T--)
	{
		int n,X;
		cin>>n>>X;
		int i,A[n];
		for(i=0;i<n;i++)
			cin>>A[i];
		Solution ob;
        cout <<  ob.find3Numbers(A, n, X) << endl;
    }
}

// } Driver Code Ends