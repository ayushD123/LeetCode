//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution
{
    public:
    //Function to check if brackets are balanced or not.
    bool ispar(string x)
    {
        // Your code here
        stack<char> st;
        
        for(auto it:x){
            
            
            if(!st.empty()){
               // cout<<it<<" "<<st.top()<<endl;
                if(st.top()=='(' && it==')') st.pop();
                else if(st.top()=='{' && it=='}') st.pop();
                else if(st.top()=='[' && it==']') st.pop();
                else st.push(it);
            }else{
               st.push(it); 
            }
            
        }
       
        if(st.empty()) return true;
        return false;
    }

};

//{ Driver Code Starts.

int main()
{
   int t;
   string a;
   cin>>t;
   while(t--)
   {
       cin>>a;
       Solution obj;
       if(obj.ispar(a))
        cout<<"balanced"<<endl;
       else
        cout<<"not balanced"<<endl;
   }
}
// } Driver Code Ends