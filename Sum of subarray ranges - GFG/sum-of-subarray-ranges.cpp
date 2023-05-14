//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    long long subarrayRanges(int n, vector<int> &nums) {
        // code here
      // int n=nums.size();
        long long ans=0;
        for(int i=0;i<n;++i){
            int maxx=nums[i];
            int minn=nums[i];
            for(int j=i;j<n;++j){
                maxx=max(maxx,nums[j]);
                minn=min(minn,nums[j]);
                ans+=(maxx-minn);
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
        int N;
        cin >> N;

        vector<int> arr(N);
        for (int i = 0; i < N; i++) cin >> arr[i];

        Solution obj;
        cout << obj.subarrayRanges(N, arr) << endl;
    }
    return 0;
}
// } Driver Code Ends