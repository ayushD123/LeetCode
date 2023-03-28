//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;



// } Driver Code Ends
//User function template for C++
class Solution{
public:	
	
	int countTriplet(int arr[], int n)
	{
	    // Your code goes here
	    
	   
	    sort(arr,arr+n,greater<int>());
	   
	    int cnt=0;
	    for(int i=0;i<n-2;++i){
	        int x=arr[i];
	        int left=i+1;
	        int right=n-1;
	        while(left<right){
	            int sum=arr[left]+arr[right];
	            if(sum==x){
	                cnt++;
	                left++;
	                right--;
	            }else{
	                if(sum<x){
	                right--;
	            }else{
	                left++;
	            } 
	            }
	           
	        }
	    }
	    return cnt;
	}
};

//{ Driver Code Starts.


int main() 
{
   	
   	ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        int arr[n];
        for(int i = 0; i < n; i++)
        	cin >> arr[i];

        Solution ob;
        cout << ob.countTriplet(arr, n) << "\n";

    }

    return 0;
}
// } Driver Code Ends