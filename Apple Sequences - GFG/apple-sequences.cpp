//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
//User function Template for C++

class Solution{   
public:
    int appleSequences(int n, int k, string s){
        // code here 
         int i=0,j=1;
        int ans=0;
        if(s.length()<3){
            return s.length();
        }
       
    
        vector<int> mp(26,0);
        mp[s[0]-'A']++;
        mp[s[1]-'A']++;
        while(j<s.length() && i<=j){
            int t=(j-i+1);
           // cout<<j<<" "<<t<<" "<<*max_element(mp.begin(),mp.end())<<endl;
            if(k==0){
                if((t==(mp[0]))){
               ans=max(ans,t);
               j++;
                if((j)<s.length())
               mp[s[j]-'A']++;
           }else{
                mp[s[i]-'A']--;
               i++;
           }}else{
                if(t-(mp[0])<=k){
                j++;
           //   cout<<t<<" "<<*max_element(mp.begin(),mp.end())<<endl;
                ans=max(ans,t);
                if((j)<s.length())
               mp[s[j]-'A']++;
            }else{
                mp[s[i]-'A']--;
                i++;
                
            }
           }
           
            
        }
        return ans;
    }
};

//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N, M;
        cin >> N >> M;
        string arr;
        cin >> arr;
        
        Solution ob;
        cout << ob.appleSequences(N, M, arr) << endl;
    }
    return 0; 
} 
// } Driver Code Ends