//{ Driver Code Starts
#include <bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
class Solution{   
public:

void computeLPSArray(string pat, int M, vector<int> &lps) {
    int len = 0;
    int i = 1;
    lps[0] = 0;
    
    while (i < M) {
        if (pat[i] == pat[len]) {
            len++;
            lps[i] = len;
            i++;
        }
        else {
            if (len != 0) {
                len = lps[len-1];
            }
            else {
                lps[i] = 0;
                i++;
            }
        }
    }
}

void KMPSearch(string pat, string txt,vector<int> &ans) {
    int M = pat.length();
    int N = txt.length();
    vector<int> lps(M);
    
    computeLPSArray(pat, M, lps);
    
    int i = 0;
    int j = 0;
    
    while (i < N) {
        if (pat[j] == txt[i]) {
            i++;
            j++;
        }
        if (j == M) {
          //  cout << "Pattern found at index " << i-j << endl;
            ans.push_back(i-j+1);
            j = lps[j-1];
        }
        else if (i < N && pat[j] != txt[i]) {
            if (j != 0) {
                j = lps[j-1];
            }
            else {
                i++;
            }
        }
    }
}

    int findLastOccurence(string A,string B){
        //Code Here
        vector<int> ans;
    KMPSearch(B,A,ans);
    if(ans.size()==0) return -1;
    return ans[ans.size()-1];
    }
};

//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        string A,B;
        cin>>A>>B;
        Solution ob;
        cout<<ob.findLastOccurence(A,B)<<"\n";
        
    } 
    return 0; 
}
// } Driver Code Ends