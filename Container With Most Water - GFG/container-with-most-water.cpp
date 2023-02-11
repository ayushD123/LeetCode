//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;
// int maxArea(int A[], int len);

// } Driver Code Ends
//User function template for C++

long long maxArea(long long height[], int len)
{
    // Your code goes here
    int lp=0;
    int rp=len-1;
    long long ans=(min(height[lp],height[rp])*(rp));
    while(lp<rp){
        if(height[lp]<height[rp]){
                lp++;
            }else{
                rp--;
                }
                ans=max(ans,(min(height[lp],height[rp])*(rp-lp)));
    }
    return ans;
}

//{ Driver Code Starts.

// Driver code
int main()
{
	int t;
	cin>>t;
	while(t--)
    {
        int n;
        cin>>n;
        long long arr[n];
        for(int i=0;i<n;i++)
            cin>>arr[i];
        cout<<maxArea(arr,n)<<endl;
    }
return 0;
}

// } Driver Code Ends