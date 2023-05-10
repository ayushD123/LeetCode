//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    //Function to find largest rectangular area possible in a given histogram.
    long long getMaxArea(long long heights[], int n)
    {
        // Your code here
         stack<long long> st;
        
     
        vector<long long> l(n,-1);
        vector<long long> r(n,-1);
        for(int i=n-1;i>=0;i--){
            while(!st.empty() && heights[st.top()]>=heights[i]){
                st.pop();
            }
            if(!st.empty()){
                r[i]=st.top();
            }
            st.push(i);
            
        }
        while(!st.empty()) st.pop();
        for(int i=0;i<n;i++){
            while(!st.empty() && heights[st.top()]>=heights[i]){
                st.pop();
            }
            if(!st.empty()){
                l[i]=st.top();
            }
            st.push(i);
            
        }
             long long ans=0;
        for(int i=0;i<n;++i){
            
                 if(l[i]==(-1)){
                l[i]=-1;
            }
             if(r[i]==(-1)){
                r[i]=n;
            }
            
            long long h=heights[i]*(r[i]-l[i]-1);
            ans=max(ans,h);
           // cout<<h<<" "<<i<<" "<<l[i]<<" "<<r[i]<<endl;
        }
       
       return ans;
    }
};


//{ Driver Code Starts.

int main()
 {
    long long t;

    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        
        long long arr[n];
        for(int i=0;i<n;i++)
            cin>>arr[i];
        Solution ob;
        cout<<ob.getMaxArea(arr, n)<<endl;
    
    }
	return 0;
}

// } Driver Code Ends