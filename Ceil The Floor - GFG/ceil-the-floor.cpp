//{ Driver Code Starts

#include <bits/stdc++.h>

using namespace std;

pair<int, int> getFloorAndCeil(int arr[], int n, int x);

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, x;
        cin >> n >> x;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        auto ans = getFloorAndCeil(arr, n, x);
        cout << ans.first << " " << ans.second << "\n";
    }
    return 0;
}

// } Driver Code Ends


pair<int, int> getFloorAndCeil(int arr[], int n, int x) {
    // code here
    sort(arr,arr+n);
    int max=*max_element(arr,arr+n);
    int min=*min_element(arr,arr+n);
    int fl=lower_bound(arr,arr+n,x)-arr;
    pair<int,int> ans;
    if(x<min){
        ans.first=-1;
    }
    if(x>max){
        ans.second=-1;
    }
    ans.first=arr[fl-1];
    if(arr[fl]==x){
        ans.first=x;
    }
    int cl=lower_bound(arr,arr+n,x)-arr;
    if(cl>=n){
        return ans;
    }
    ans.second=arr[cl];
    if(x<min){
        ans.first=-1;
    }
    if(x>max){
        ans.second=-1;
    }
    return ans;
}