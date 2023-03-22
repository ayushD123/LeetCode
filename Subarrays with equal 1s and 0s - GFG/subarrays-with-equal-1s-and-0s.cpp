//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution{
  public:
    //Function to count subarrays with 1s and 0s.
    long long int countSubarrWithEqualZeroAndOne(int arr[], int n)
    {
        //Your code here
        unordered_map<int,int> mp;
        for(int i=0;i<n;++i){
            if(arr[i]==0){
                arr[i]=-1;
            }
        }
        int pre=0;
        long long cnt=0;
        for(int i=0;i<n;++i){
          pre+=arr[i];
          if(pre==0){
              cnt++;
             // continue;
          }
          if(mp.find(pre)!=mp.end()){
              cnt+=mp[pre];
          }
          mp[pre]++;
        }
        return cnt;
    }
};

//{ Driver Code Starts.

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
	int n,i;
	cin>>n;
	int arr[n];
	for(i=0;i<n;i++)
	cin>>arr[i];
	Solution obj;
	cout<< obj.countSubarrWithEqualZeroAndOne(arr, n)<<"\n";
	}
	return 0;
}

// } Driver Code Ends