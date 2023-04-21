//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++
class Solution{
public:
	int rowWithMax1s(vector<vector<int> > arr, int n, int m) {
	    // code here
	    int ans=0;
	    int ansind=-1;
	    for(int i=0;i<arr.size();++i){
	        vector<int> v=arr[i];
	        int low=0;
	        int high=v.size()-1;
	        int tmp=m;
	        while(low<=high){
	            int mid=(low+high)/2;
	            if(v[mid]==1){
	                tmp=mid;
	                high=mid-1;
	            }else{
	                low=mid+1;
	            }
	        }
	       int nos=m-tmp;
	      // cout<<nos<<endl;
	       if(nos>ans){
	           ans=nos;
	           ansind=i;
	       }
	       
	        
	    }
	    return ansind;
	}

};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector< vector<int> > arr(n,vector<int>(m));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin>>arr[i][j];
            }
        }
        Solution ob;
        auto ans = ob.rowWithMax1s(arr, n, m);
        cout << ans << "\n";
    }
    return 0;
}

// } Driver Code Ends