//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    vector<int> nextPermutation(int N, vector<int> arr){
        // code here
        map<int,int> mp;
        int a=0;
        int b=0;
        int flag=1;
        for(int i=N-1;i>=0;--i){
            int x=arr[i];
            for(auto it:mp){
                if(it.first>x){ //not distinct
                     a=i;
                    b=it.second;
                    flag=0;
                    break;
                }
            }
            if(flag==0){
                break;
            }
            mp[x]=i;
        }
      //  cout<<a<<" "<<b;
        vector<int> ans;
        if(flag==0){
           int i=0;
           while(i!=a){
               ans.push_back(arr[i]);
               i++;
           }
           ans.push_back(arr[b]);
           vector<int> tmp;
          
           for(int j=i;j<N;++j){
               if(j!=b)
               tmp.push_back(arr[j]);
           }
           sort(tmp.begin(),tmp.end());
           for(auto it:tmp){
               ans.push_back(it);
           }
           return ans;
        }
        sort(arr.begin(),arr.end());
        return arr;
       // cout<<ans.size();
        
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        vector<int> arr(N);
        for(int i = 0;i < N;i++)
            cin>>arr[i];
        
        Solution ob;
        vector<int> ans = ob.nextPermutation(N, arr);
        for(int u: ans)
            cout<<u<<" ";
        cout<<"\n";
    }
    return 0;
}
// } Driver Code Ends