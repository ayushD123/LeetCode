//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;



// } Driver Code Ends

class Solution{
  public:
    vector <int> countDistinct (int A[], int n, int k)
    {
        //code here.
        unordered_map<int,int> st;
        vector<int> ans;
        for(int i=0;i<k;++i){
           st[A[i]]++;
        }
        ans.push_back(st.size());
        for(int i=k;i<n;++i){
            st[A[i-k]]--;
            if(st[A[i-k]]==0)
            st.erase(A[i-k]);
            st[A[i]]++;
            ans.push_back(st.size());
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

        int n, k;
        cin >> n >> k;
        int a[n];
        for (int i = 0; i < n; i++) 
        	cin >> a[i];
        Solution obj;
        vector <int> result = obj.countDistinct(a, n, k);
        for (int i : result) 
        	cout << i << " ";
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends