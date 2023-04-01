//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution{
public:
      string maxSum(string w,char x[], int b[],int n){
          // code here    
          vector<int> arr;
          unordered_map<char,int> mp;
          for(auto it:w){
              char a=it;
              mp[it]=(int)a;
              
          }
          for(int i=0;i<n;++i){
              mp[x[i]]=b[i];
          }
          for(auto it:w){
              arr.push_back(mp[it]);
          }
         int start=0;
         int ans=0;
         int end=0;
         int s=0;
         int sum=0;
         for(int i=0;i<arr.size();++i){
             sum+=arr[i];
             if(sum>ans){
                 ans=sum;
                 start=s;
                 end=i;
             }
             if(sum<0){
                 sum=0;
                 s=i+1;
             }
         }
        // cout<<start<<" "<<end;
         string anas;
         for(int i=start;i<=end;++i){
             anas.push_back(w[i]);
         }
         return anas;
      }
};

//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        string w;
        cin>>w;
        int n;
        cin>>n;
        char x[n];
        int b[n];
        for(int i = 0;i<n;i++)
            cin>>x[i];
        for(int i = 0;i<n;i++)
            cin>>b[i];
        Solution ob;
        cout << ob.maxSum(w,x,b,n) << endl;
    }
    return 0; 
}
// } Driver Code Ends