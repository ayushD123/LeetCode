//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
#define MAX 1000


// } Driver Code Ends
/*You are required to complete this method*/

class Solution{
  public:
  int largestRectangleArea(vector<int>& heights,int n) {
        
        stack<int> st;
        
     
        vector<int> l(n,-1);
        vector<int> r(n,n);
        for(int i=n-1;i>=0;i--){
            while(!st.empty() && heights[st.top()]>=heights[i]){
                st.pop();
            }
            if(!st.empty()){
                r[i]=st.top();
            }
            st.push(i);
            
        }
        while(!st.empty()) st.pop();
        for(int i=0;i<n;i++){
            while(!st.empty() && heights[st.top()]>=heights[i]){
                st.pop();
            }
            if(!st.empty()){
                l[i]=st.top();
            }
            st.push(i);
            
        }
             int ans=0;
        for(int i=0;i<n;++i){
            
            //      if(l[i]==(-1)){ //if element has no nxt greater at left
            //     l[i]=-1;
            // }
            //  if(r[i]==(-1)){ //if element has no nxt greater at right
            //     r[i]=n;
            // }
            
            int h=heights[i]*(r[i]-l[i]-1);
            ans=max(ans,h);
           // cout<<h<<" "<<i<<" "<<l[i]<<" "<<r[i]<<endl;
        }
       
       return ans;
     }
    int maxArea(int matrix[MAX][MAX], int n, int m) {
        // Your code here
          
        vector<int> curr(m,0);
        for(int i=0;i<m;++i){
            if(matrix[0][i]==1){
                curr[i]=1;
            }
        }
        //  for(auto it:curr){
        //         cout<<it<<" ";
        //     }
        // cout<<endl;
      //  cout<<n<<" "<<m<<endl;
        int ans=largestRectangleArea(curr,m);
        for(int i=1;i<n;++i){
            for(int j=0;j<m;++j){
                if(matrix[i][j]==1){
                    curr[j]+=1;
                }else{
                    curr[j]=0;
                }
            }
            // for(auto it:curr){
            //     cout<<it<<" ";
            // }
           // cout<<endl;
            ans=max(ans,largestRectangleArea(curr,m));
        }
        return ans;
        
    }
};


//{ Driver Code Starts.
int main() {
    int T;
    cin >> T;

    int M[MAX][MAX];

    while (T--) {
        int n, m;
        cin >> n >> m;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> M[i][j];
            }
        }
        Solution obj;
        cout << obj.maxArea(M, n, m) << endl;
    }
}

// } Driver Code Ends