//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution
{
    public:
    typedef long long ll;
    long long countKdivPairs(int A[], int n, int K)
    {
        //code here
        unordered_map<ll,int> mp;
        ll ans=0;
        for(int i=0;i<n;++i){
            ll rem=A[i]%K;
            if(rem==0){
                ans+=mp[0];
            }else
            ans+=mp[K-rem];
            mp[rem]++;
        }
        // for(auto it:mp){
        //     cout<<it.first<<":"<<it.second<<endl;
        // }
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

		int a[n];
		for (int i = 0; i < n; i++)
			cin >> a[i];

		int k;
		cin >> k;

        Solution ob;
		cout << ob. countKdivPairs(a, n , k) << "\n";



	}


	return 0;
}

// } Driver Code Ends