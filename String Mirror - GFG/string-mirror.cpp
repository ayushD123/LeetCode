//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    string stringMirror(string str){
        // Code here
        int k=1;
        int i=1;
        while(i<str.length()){
            if(k!=1){
                if(str[i-1]>=str[i]){
                     k++;
                        i++;
                }else{
                    break;
                }
            }else if(str[i-1]>str[i]){
                k++;
                        i++;
            }else{
                break;
            }
           
        }
        string ans="";
        for(int j=0;j<k;++j){
            ans.push_back(str[j]);
        }
        string t=ans;
        reverse(ans.begin(),ans.end());
        return t+ans;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        string str;
        cin>>str;
        Solution ob;
        string res=ob.stringMirror(str);
        cout<<res<<endl;
    }
}
// } Driver Code Ends