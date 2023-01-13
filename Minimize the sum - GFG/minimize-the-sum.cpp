//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
public:
    int minimizeSum(int N, vector<int> arr) {
        // code here
        priority_queue <int, vector<int>, greater<int> > st;
        for(auto it:arr){
          st.push(it);
     }

        // for(auto it:arr){
        //     st.insert(it);
        // }
        int ans=0;
        while(st.size()>1){
          // for(auto it:st){
          //      cout<<it<<" ";
          // }
          // cout<<endl;
            int a=st.top();
            st.pop();
            int b=st.top();
            
            ans+=(a+b);
          //  cout<<a<<"+"<<b<<"="<<a+b<<endl;
            st.push(a+b);
            st.pop();
            
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
	int t;
    cin>>t;
    while(t--) {
        int n;
        cin>>n;
        vector<int> arr(n);
        for(int i = 0; i < n; i++)
            cin>>arr[i];
        Solution obj;
        cout << obj.minimizeSum(n, arr) << "\n";
    }
}
// } Driver Code Ends