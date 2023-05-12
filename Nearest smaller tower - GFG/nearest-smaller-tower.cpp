//{ Driver Code Starts
//Initial Template for C++


#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution
{
public:
    vector<int> nearestSmallerTower(vector<int> arr)
    {
        // code here
        int n=arr.size();
        
        vector<int> right(n,-1);
        vector<int> left(n,-1);
        stack<int> st;
        for(int i=n-1;i>=0;i--){
            while(!st.empty() && arr[i]<=arr[st.top()]){
                st.pop();
            }
            if(!st.empty()){
                right[i]=st.top();
            }
            st.push(i);
        }
        while(!st.empty()) st.pop();
        for(int i=0;i<n;i++){
            while(!st.empty() && arr[i]<=arr[st.top()]){
                st.pop();
            }
            if(!st.empty()){
                left[i]=st.top();
            }
            st.push(i);
        }
        // for(int i=0;i<n;++i){
        //     cout<<left[i]<<" ";
            
        // }
        // cout<<endl;
        // for(int i=0;i<n;++i){
            
        //     cout<<right[i]<<" ";
        // }
        // cout<<endl;
        vector<int> ans(n,-1);
        for(int i=0;i<n;++i){
            if(left[i]<0 && right[i]>=0){
                ans[i]=right[i];
            }else{
                if(left[i]>=0 && right[i]<0){
                   ans[i]=left[i]; 
                }else if(left[i]>=0 && right[i]>=0){
                   int l=abs(left[i]-i); 
                   int r=abs(right[i]-i); 
                   if(l<r){
                       ans[i]=left[i];
                   }else if(l>r){
                       ans[i]=right[i];
                   }else{
                       ans[i]=arr[left[i]]>arr[right[i]]?right[i]:left[i];
                   }
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
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> v(n);
        for (int i = 0; i < n; i++)
        {
            cin >> v[i];
        }
        Solution ob;
        vector<int> ans = ob.nearestSmallerTower(v);
        for (int i = 0; i < n; i++)
        {
            cout << ans[i] << " ";
        }
        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends