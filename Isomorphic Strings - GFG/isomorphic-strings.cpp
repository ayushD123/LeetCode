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
    bool areIsomorphic(string str1, string str2)
    {
        if(str1.length()!=str2.length()){
            return 0;
        }
        // Your code here
       int arr1[255]={};
       int arr2[255]={};
       
       for(int i=0;i<str1.length();++i){
           if(arr1[str1[i]]!=arr2[str2[i]]){
               return 0;
           }
           
           arr1[str1[i]]=i+1;
           arr2[str2[i]]=i+1;
       }
       return 1;
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