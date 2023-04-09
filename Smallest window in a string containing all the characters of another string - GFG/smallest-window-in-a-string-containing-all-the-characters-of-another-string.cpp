//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    //Function to find the smallest window in the string s consisting
    //of all the characters of string p.
    string smallestWindow (string s, string p)
    {
        // Your code here
        unordered_map<char,int> mp;
        for(auto it:p){
            mp[it]++;
        }
        int count=mp.size();
        int ans=1e9+7;
        int left=0;
        int right=0;
        int start=0;
        while(right<s.length()){
            mp[s[right]]--;
            if(mp[s[right]]==0){
                count--;
            }
            if(count==0){
               
                while(left<=right && count==0){
                    if((right-left+1)<ans){
                       ans=min(ans,right-left+1);
                       start=left;
                    }
                   
                   mp[s[left]]++;
                   if(mp[s[left]]>0){
                       count++;
                   }
                   left++;
                }
            }
            right++;
        }
        if(ans==(1e9+7)){
            return "-1";
        }
        
        return s.substr(start,ans);
    }
};

//{ Driver Code Starts.
int main()
 {
    int t;
    cin>>t;
    while(t--)
    {
        string s;
        cin>>s;
        string pat;
        cin>>pat;
        Solution obj;
        cout<<obj.smallestWindow(s, pat)<<endl;
        
    }
	return 0;
}
// } Driver Code Ends