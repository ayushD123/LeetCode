//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution{
    public:
    // arr[] : int input array of integers
    // k : the quadruple sum required
    vector<vector<int> > fourSum(vector<int> &arr, int k) {
        // Your code goes here
        sort(arr.begin(),arr.end());
        int n=arr.size();
        vector<vector<int>> ans;
        set<vector<int>> st;
        for(int i=0;i<n-3;++i){
          int x=k-arr[i];
          for(int j=i+1;j<n-2;++j){
              int y=x-arr[j];
              int left=j+1;
              int right=n-1;
              while(left<right){
                  int sum=arr[left]+arr[right];
                  if(sum==y){
                      vector<int> t= {arr[i],arr[j],arr[left],arr[right]};
                     // ans.push_back(t);
                      st.insert(t);
                      left++;
                      right--;
                  }else{
                      if(sum<y){
                          left++;
                      }else{
                          right--;
                      }
                  }
              }
          }
        }
        for(auto it:st){
            ans.push_back(it);
        }
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k, i;
        cin >> n >> k;
        vector<int> a(n);
        for (i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        vector<vector<int> > ans = ob.fourSum(a, k);
        for (auto &v : ans) {
            for (int &u : v) {
                cout << u << " ";
            }
            cout << "$";
        }
        if (ans.empty()) {
            cout << -1;
        }
        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends