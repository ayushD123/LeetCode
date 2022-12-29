//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    vector<int> asteroidCollision(int N, vector<int> &asteroids) {
        // code here
          stack<int> st;
        for(auto it:asteroids){
           //  stack<int> temp=st;
            if(it>0 || st.empty()){
                st.push(it);
            }else {
               while(!st.empty() && abs(it)>(st.top()) && st.top()>0){
                st.pop();
                   
                }
                if(!st.empty() && (st.top())==abs(it) ){
                    st.pop();
                }else{
                    if(st.empty() || st.top()<0){
                    st.push(it);
                }
                }
                
                
            }
            
        }
        vector<int> ans(st.size());
        for(int i=st.size()-1;i>=0;i--){
            ans[i]=st.top();
            st.pop();
            
        }
        
       // reverse(ans.begin(),ans.end());
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

        vector<int> asteroids(N);
        for (int i = 0; i < N; i++) cin >> asteroids[i];

        Solution obj;
        vector<int> ans = obj.asteroidCollision(N, asteroids);
        for (auto &it : ans) cout << it << ' ';
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends