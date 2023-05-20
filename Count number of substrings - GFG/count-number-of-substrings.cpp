//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

class Solution
{
  public:
  
  long long int atmost(string &s,int k){
        if (s.size() == 0 || k==0) {
        return 0;
    }
    
       int left=0;
        int right=0;
        long long ans=0;
        int dist=0;
        int n=s.length();
        int mp[26]={0};
        while(right<n){
            if(mp[s[right]-'a']==0) dist++;
            mp[s[right]-'a']++;
          
        
        while(left<right && dist>k){
            mp[s[left]-'a']--;
            if(mp[s[left]-'a']==0) dist--;
            left++;
            
        }
      // if(mp.size()==k)
        ans+=right-left+1; 
            right++;
        }
       
  return ans;
  }
    long long int substrCount (string s, int k) {
    	//code here
    	long long int ans=atmost(s,k)-atmost(s,k-1);
    	return (ans);
    }
};

//{ Driver Code Starts.


int main()
{
    int t; cin >> t;
    while (t--)
	{
		string s; cin >> s;
		int k; cin >> k;
		Solution ob;
		cout <<ob.substrCount (s, k) << endl;
	}
}
// } Driver Code Ends