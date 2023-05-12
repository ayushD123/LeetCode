//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    string preToPost(string str) {
         stack<string> st;
        for(int i=str.length()-1;i>=0;i--){
            if((str[i]>='A' && str[i]<='Z') || (str[i]>='a' && str[i]<='z' )){
                string tmp="";
                tmp+=str[i];
                
                st.push(tmp);
            }else{
                string a=st.top();
                st.pop();
                string b=st.top();
                st.pop();
                st.push(a+b+str[i]);
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
        cout << obj.preToPost(prefix) << endl;

        // cout << "~\n";
    }
    // fclose(stdout);

    return 0;
}

// } Driver Code Ends