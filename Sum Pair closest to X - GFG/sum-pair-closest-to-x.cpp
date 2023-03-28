//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution{   
public:
    vector<int> sumClosest(vector<int>arr, int x)
    {
        // code here
        int i=0;
        int j=arr.size()-1;
        int mindiff=99999;
        vector<int> ans;
        while(i<j){
          int  sum=arr[i]+arr[j];
           int diff=abs(x-sum);
            if(diff<mindiff){
                mindiff=diff;
                ans={arr[i],arr[j]};
                if(diff==0){
                    return ans;
                }
            }
            if(sum>x){
                j--;
            }else{
                i++;
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, x;
        cin >> n >> x;
        vector<int> arr(n);
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.sumClosest(arr, x);
        cout << ans[0] << " " << ans[1] << "\n";
    }
    return 0;
}
// } Driver Code Ends