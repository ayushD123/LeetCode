//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int sumSubarrayMins(int N, vector<int> &arr) {
        // code here
         int n=arr.size();
        int mod=1e9+7;
        vector<int> left(n,-1);
        vector<int> right(n,n);
        stack<int> st;
        for(int i=n-1;i>=0;i--){
            while(!st.empty() && arr[st.top()]>=arr[i]){
                st.pop();
            }
            if(!st.empty()){
                right[i]=st.top();
            }
            st.push(i);
        }
        while(!st.empty()){
            st.pop();
        }
         for(int i=0;i<n;i++){
            while(!st.empty() && arr[st.top()]>arr[i]){
                st.pop();
            }
            if(!st.empty()){
                left[i]=st.top();
            }
             st.push(i);
        }
        
        int ans=0;
        for(int i=0;i<n;++i){
            // v[i]=(right[i]-arr[i]-1)+(arr[i]-left[i]-1);
            int leftn=i-left[i]-1;
            int rightn=right[i]-i-1;
           // cout<<leftn<<" "<<rightn<<endl;
            long long cal=(long long)arr[i]%mod*(leftn%mod+1)%mod*(rightn%mod+1)%mod;
            ans+=cal;
            ans=ans%mod;
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;

        vector<int> arr(N);
        for (int i = 0; i < N; i++) cin >> arr[i];

        Solution obj;
        cout << obj.sumSubarrayMins(N, arr) << endl;
    }
    return 0;
}
// } Driver Code Ends