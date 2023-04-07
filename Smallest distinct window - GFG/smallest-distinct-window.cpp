//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
    public:
    int findSubString(string str)
    {
        int n=str.length();
        // Your code goes here 
        set<char> st;
        int ans=1e9;
        for(auto it:str){
            st.insert(it);
        }
        int x=st.size();
        if(x==1){
            return 1;
        }
        unordered_map<char,int> mp;
        int left=0;
        int right=0;
        while(right<n){
            mp[str[right]]++;
            while(left<right && (mp.size()==x)){
                mp[str[left]]--;
                if( mp[str[left]]==0){
                    mp.erase(str[left]);
                }
                ans=min(ans,right-left+1);
                left++;
                
            }
            
            
            right++;
        }
        return ans;
    }
};

//{ Driver Code Starts.
// Driver code
int main() {
    int t;
    cin >> t;
    while (t--) {

        string str;
        cin >> str;
        Solution ob;
        cout << ob.findSubString(str) << endl;
    }
    return 0;
}
// } Driver Code Ends