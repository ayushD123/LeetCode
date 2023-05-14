//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    string removeKdigits(string num, int k) {
        stack<char> st;
        for(auto it:num){
            while(!st.empty() && k>0 && (st.top()>it)){
                 //cout<<st.top()<<" ";
                st.pop();
               
                k--;
            }
            st.push(it);
         //   if(k<=0) break;
        }
        while(!st.empty() && k>0){
            st.pop();
            k--;
        }
        if(st.empty()) return "0";
        string ans="";
        
        while(!st.empty()){
            ans+=st.top();
            st.pop();
        };
       // cout<<ans.back();
        while(ans.back()=='0' && ans.length()>1) ans.pop_back();
        reverse(ans.begin(),ans.end());
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string S;
        cin >> S;
        int K;
        cin >> K;
        Solution obj;
        cout << obj.removeKdigits(S, K) << endl;
    }
    return 0;
}

// } Driver Code Ends