//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    string preToInfix(string str) {
        // Write your code here
        stack<string> st;
        for(int i=str.length()-1;i>=0;i--){
            char c=str[i];
            if((c>='A' && c<='Z') ||(c>='a' && c<='z')){
                string tmp="";
                tmp+=c;
                st.push(tmp);
            }else{
                string a=st.top();
                st.pop();
                string b=st.top();
                st.pop();
                
                st.push('('+a+c+b+')');
            }
        }
        return st.top();
    }
};

//{ Driver Code Starts.
int main() {
    int t = 1;
    cin >> t;

    // freopen ("output_gfg.txt", "w", stdout);

    while (t--) {
        // Input
        string prefix;
        cin >> prefix;

        Solution obj;
        cout << obj.preToInfix(prefix) << endl;

        // cout << "~\n";
    }
    // fclose(stdout);

    return 0;
}

// } Driver Code Ends