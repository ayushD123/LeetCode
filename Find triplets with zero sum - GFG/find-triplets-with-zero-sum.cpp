//{ Driver Code Starts
#include<bits/stdc++.h>
#include<stdlib.h>
#include<iostream>
using namespace std;

// } Driver Code Ends
/* You are required to complete the function below
*  arr[]: input array
*  n: size of array
*/
class Solution{
  public:
    //Function to find triplets with zero sum.
    bool findTriplets(int arr[], int n)
    { 
        //Your code here
       // using 2 pointers
        sort(arr,arr+n);
        for(int i=0;i<n-2;++i){
            int x=arr[i];
           // x=x*(-1);
            int left=i+1;
            int right=n-1;
            while(left<right){
                int sum=arr[left]+arr[right]+x;
                if(sum==(0)){
                    return 1;
                }
                if(sum>0){
                    right--;
                }else{
                    left++;
                }
            }
            
        }
        return 0;
        
        //using hashing(TLE)
        // for(int i=0;i<n-1;i++){
        //     int x=(-1)*arr[i];
        //     unordered_set<int> st;
        //     for(int j=i+1;j<n;++j){
                
        //         if(st.find(x-arr[j])!=st.end()){
        //             return true;
        //         }
        //         st.insert(arr[j]);
        //     }
        // }
        // return 0;
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
	cin>>t;
	while(t--){
    	int n;
    	cin>>n;
    	int arr[n]={0};
    	for(int i=0;i<n;i++)
    		cin>>arr[i];
    	Solution obj;
        if(obj.findTriplets(arr, n))
            cout<<"1"<<endl;
        else 
            cout<<"0"<<endl;
	}
    return 0;
}
// } Driver Code Ends