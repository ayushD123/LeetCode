//{ Driver Code Starts
//Initial function template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

class Solution{
public:
    //Function to count subarrays with sum equal to 0.
    long long int findSubarray(vector<long long int> &nums, int n ) {
        //code here
         unordered_map<int,int> map;
      //  int n=nums.size();
        int curr=0;
        long long cnt=0;
        for(int i=0;i<nums.size();++i){
            curr+=nums[i];
            
            if(curr==0){
                cnt++;
            }
            if(map.find(curr-0)!=map.end()){
                cnt+=map[curr-0];
            }
           // cout<<cnt<<" ";
            map[curr]++;
        }
     //   cout<<map.size();
        // if(map.size()==1 && n>1){
        //     return n*(n+1)/2;
        // }
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
        int n;
        cin>>n; //input size of array
       
        vector<long long int> arr(n,0);
        
        for(int i=0;i<n;i++)
            cin>>arr[i]; //input array elements
        Solution ob;
        cout << ob.findSubarray(arr,n) << "\n";
    }
	return 0;
}
// } Driver Code Ends