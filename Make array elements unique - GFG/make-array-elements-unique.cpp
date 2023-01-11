//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    long long int minIncrements(vector<int> arr, int N) {
        // Code here
        sort(arr.begin(),arr.end());
        map<int,int> freq;
        for(auto it:arr){
            freq[it]++;
        }
        vector<int> rep;
        for(auto it:arr){
            if(freq[it]>1){
                rep.push_back(it);
                freq[it]--;
            }        
            
        }
        int ans=0;
        for(auto  it:rep){
            int x=it;
            while(freq.find(it)!=freq.end()){
                it++;
            }
            ans+=(it-x);
            freq[it]+=1;
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
        for (int i = 0; i < N; i++) {
            cin >> arr[i];
        }
        Solution obj;
        cout << obj.minIncrements(arr, N) << endl;
    }
}
// } Driver Code Ends