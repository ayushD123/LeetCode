//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int minimumMultiplications(vector<int>& arr, int start, int end) {
        // code here
        int l=1e5;
        //sort(arr.begin(),arr.end());
        queue<pair<int,int>> st;//no of multiplication and ans
        vector<int> dis(l,1e9);
        dis[start]=0;
        st.push({0,start});
        while(!st.empty()){
            auto it=(st.front());
            int cnt=it.first;
            int mul=it.second;
         //   cout<<cnt<<" "<<mul<<endl;
            
            st.pop();
            if(mul==end){
                return cnt;
            }
            // if(mul>end){
            //     continue;
            // }
            for(auto it:arr){
                int t=(mul*it)%l;
                if(t==end){
                    return cnt+1;
                }
                if(dis[t]>(cnt+1)){
                    dis[t]=cnt+1;
                    st.push({cnt+1,t});
                }
            }
        }
        return -1;
    }
};


//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> arr(n);
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        int start, end;
        cin >> start >> end;
        Solution obj;
        cout << obj.minimumMultiplications(arr, start, end) << endl;
    }
}

// } Driver Code Ends