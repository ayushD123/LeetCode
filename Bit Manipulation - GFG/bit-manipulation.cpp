//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    void bitManipulation(int num, int i) {
        // your code here
        if(num&(1<<i-1)){
            cout<<1<<" ";
        }else{
            cout<<0<<" ";
        }
        int st=num|(1<<i-1);
        cout<<st<<" ";
        int cl=num&(~(1<<i-1));
        cout<<cl<<" ";
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i;
        cin >> n >> i;
        Solution ob;
        ob.bitManipulation(n, i);
        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends