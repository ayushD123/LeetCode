//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int mostBalloons(int n, pair<int, int> points[]) {
        // Code here
        
        if (n <=2) {
            return n;
        }
        int result = 2;
        for (int i = 0; i < n; i++) {
            unordered_map<double, int> cnt;
            int c=0;
            for (int j = 0; j < n; j++) {
                if (j != i) {
                    if((points[j].second - points[i].second==0) && (points[j].first - points[i].first==0)){
                       c++;
                       continue;
                    }
                    cnt[atan2(points[j].second - points[i].second, points[j].first - points[i].first)]++;
                }
            }
            for (auto count : cnt) {
                result = max(result, count.second +1 +c);
            }
        }
        return result;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        pair<int, int> arr[N];
        for (int i = 0; i < N; i++) {
            cin >> arr[i].first;
        }
        for (int i = 0; i < N; i++) {
            cin >> arr[i].second;
        }
        Solution ob;
        cout << ob.mostBalloons(N, arr) << endl;
    }
}
// } Driver Code Ends