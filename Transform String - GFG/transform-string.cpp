//{ Driver Code Starts
#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    int transform (string A, string B)
    {
        //code here.
        if(A.length()!=B.length()) return -1;
        string t1=A;
        string t2=B;
        sort(t1.begin(),t1.end());
         sort(t2.begin(),t2.end());
         if(t1!=t2) return -1;
        int n=A.length();
        int i=n-1;
        int j=n-1;
        int cnt=0;
        while(i>=0 && j>=0){
            if(A[i]!=B[j]){
                cnt++;
                i--;
            }else{
                i--;
                j--;
            }
            
        }
       // cout<<i<<" "<<j;
      //  if(j>((n+1)/2)) return -1;
        return cnt;
    }
};


//{ Driver Code Starts.

int main () 
{
    int t; cin >> t;
    while (t--)
    {
        string A, B; 
        cin >> A >> B;
        Solution ob;
        cout <<ob.transform (A, B) << endl;
    }
}
// } Driver Code Ends