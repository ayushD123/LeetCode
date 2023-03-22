//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;
int longestSubstrDistinctChars (string S);
int main()
{
    int t; cin >> t;
    while (t--)
    {
        string S; cin >> S;

        cout << longestSubstrDistinctChars (S) << endl;
    }
}

// Contributed By: Pranay Bansal

// } Driver Code Ends


int longestSubstrDistinctChars (string s)
{
    // your code here
    unordered_map<char,int> mp;
    int left=0;
    int ans=0;
    for(int right=0;right<s.length();++right){
        char c=s[right];
        if(mp.find(c)!=mp.end() && left<=mp[c]){
            left=mp[c]+1;
        }
        int len=right-left+1;
        ans=max(ans,len);
        mp[c]=right;
    }
    return ans;
}