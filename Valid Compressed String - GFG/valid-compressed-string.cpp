//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    int checkCompressed(string s, string t) {
        // code here
        int k=0;
        for(int i=0;i<t.length();){
            
            if(t[i]+0>60){
                if(s[k]!=t[i]){
                    //cout<<k<<" "<<i;
                    return 0;
                }else{
                    k++;
                    i++;
                }
            }else{
                string temp="";
                while(i<t.length() && t[i]+0<60){
                    temp.push_back(t[i]);
                    i++;
                }
                int cnt=stoi(temp);
                k+=cnt;
            }
        }
       // cout<<k;
        if(k>s.length()) return 0;
        return 1;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string S,T;
        
        cin>>S>>T;

        Solution ob;
        cout << ob.checkCompressed(S,T) << endl;
    }
    return 0;
}
// } Driver Code Ends