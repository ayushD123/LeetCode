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
        // for(int i=0;i<n;++i){
        //      unordered_map<int,int> mp;
        //      int two_sum=X-arr[i];
        //      //two sum probelm
        //      for(int j=i+1;j<n;++j){
        //          if(mp.find(two_sum-arr[j])!=mp.end()){
        //              return 1;
        //          }
        //          mp[arr[j]]++;
                 
        //      }
        // }
        // return 0;
        sort(arr,arr+n);
        for(int i=0;i<n-2;++i){
            int k=X-arr[i];
            int left=i+1;
            int right=n-1;
            while(left<right){
                int sum=arr[left]+arr[right];
                if(sum==k){
                    return 1;
                }
                if(sum<k){
                    left++;
                }else{
                    right--;
                }
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