//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

class Solution {
  public:
    long long getSubstringWithEqual012(string str) {
        // code here
        map<pair<int,int>,int> mp;
        long long ans=0;
        int cnt1=0;
        int cnt2=0;
        int cnt0=0;
        mp[{0,0}]=0;
        for(auto it:str){
            if(it=='0'){
                cnt0++;
            }else if(it=='1'){
                cnt1++;
            }else{
                cnt2++;
            }
            pair<int,int> p={cnt0-cnt1,cnt2-cnt1};
            if((cnt0-cnt1)==0 && (cnt2-cnt1)==0){
                ans++;
            }
            if(mp.find(p)!=mp.end()){
                ans+=mp[p];
            }
            mp[p]++;
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		string s;
		cin>>s;
		Solution ob;
		cout<<ob.getSubstringWithEqual012(s)<<endl;
	}
    return 0;
}

// } Driver Code Ends