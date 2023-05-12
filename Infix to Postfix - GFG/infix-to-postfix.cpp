//{ Driver Code Starts
// C++ implementation to convert infix expression to postfix
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    // Function to convert an infix expression to a postfix expression.
    int prec(char c){
        if(c=='^') return 3;
        if(c=='*' || c=='/') return 2;
         if(c=='-' || c=='+') return 1;
         return -1;//for brackets
    }
    string infixToPostfix(string s) {
        // Your code here
        stack<char> st;
        string ans="";
        for(auto it:s){
            if((it>='a' && it<='z') || (it>='A' && it<='Z') || (it>='0' && it<='9')){
                ans+=it;
            
        }
        else if(it=='(') st.push(it);
        else if(it==')'){
            while(!st.empty() && st.top()!='('){
                ans+=st.top();
                st.pop();
            }
            st.pop();
        }
         else{
            while(!st.empty() && prec(st.top())>=prec(it)){
                ans+=st.top();
                st.pop();
            }
            st.push(it);
        }
    }
    while(!st.empty()){
        ans+=st.top();
        st.pop();
    }
    return ans;
    }
};


//{ Driver Code Starts.
// Driver program to test above functions
int main() {
    int t;
    cin >> t;
    cin.ignore(INT_MAX, '\n');
    while (t--) {
        string exp;
        cin >> exp;
        Solution ob;
        cout << ob.infixToPostfix(exp) << endl;
    }
    return 0;
}

// } Driver Code Ends