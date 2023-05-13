//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    vector<int> nextGreaterElement(int N, vector<int>& nums) {
        // code 
         vector<int> tmp=nums;
        for(auto it:nums){
            tmp.push_back(it);
        }
        stack<int> st;
        vector<int> ans(tmp.size(),-1);
        for(int i=tmp.size()-1;i>=0;i--){
            while(!st.empty() && st.top()<=tmp[i]){
                st.pop();
            }
            if(!st.empty()) ans[i]=st.top();
            st.push(tmp[i]);
        }
        for(int i=0;i<nums.size();++i){
            ans.pop_back();
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
        vector<int> ans = obj.nextGreaterElement(N, arr);
        for (auto &it : ans) {
            cout << it << ' ';
        }
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends