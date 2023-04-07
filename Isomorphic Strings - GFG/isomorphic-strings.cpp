//{ Driver Code Starts
// C++ program to check if two strings are isomorphic


#include<bits/stdc++.h>


using namespace std;
#define MAX_CHARS 256

// } Driver Code Ends
class Solution
{
    public:
    //Function to check if two strings are isomorphic.
    bool areIsomorphic(string s, string t)
    {
        
        // Your code here
        if(s.length()!=t.length()){
            return 0;
        }
         int arr1[256]={0};
        
        int arr2[256]={0};
      for(int i=0;i<s.length();++i){
        if(arr1[s[i]]!=arr2[t[i]]){
            return false;
        }
          arr1[s[i]]=i+1;
           arr2[t[i]]=i+1;
      }
       
  return true;
    }
};

//{ Driver Code Starts.

// Driver program
int main()
{
    int t;
    cin>>t;
    string s1,s2;
    while (t--) {
        cin>>s1;
        cin>>s2;
        Solution obj;
        cout<<obj.areIsomorphic(s1,s2)<<endl;
    }
    
    return 0;
}
// } Driver Code Ends