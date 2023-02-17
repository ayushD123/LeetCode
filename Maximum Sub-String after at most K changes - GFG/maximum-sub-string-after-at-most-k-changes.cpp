//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
	public:
		int characterReplacement(string s, int k){
		    // Code here
		     int i=0,j=1;
        int ans=1;
        if(s.length()<3){
            return s.length();
        }
       
    
        vector<int> mp(26,0);
        mp[s[0]-'A']++;
        mp[s[1]-'A']++;
        while(j<s.length() && i<=j){
            int t=(j-i+1);
           // cout<<j<<" "<<t<<" "<<*max_element(mp.begin(),mp.end())<<endl;
            if(k==0){
                if((t==(*max_element(mp.begin(),mp.end())))){
               ans=max(ans,t);
               j++;
                if((j)<s.length())
               mp[s[j]-'A']++;
           }else{
                mp[s[i]-'A']--;
               i++;
           }}else{
                if(t-(*max_element(mp.begin(),mp.end()))<=k){
                j++;
           //   cout<<t<<" "<<*max_element(mp.begin(),mp.end())<<endl;
                ans=max(ans,t);
                if((j)<s.length())
               mp[s[j]-'A']++;
            }else{
                mp[s[i]-'A']--;
                i++;
                
            }
           }
           
            
        }
        return ans;
		}

};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		string s;
		cin >> s;
		int k;
		cin >> k;
		Solution obj;
		int ans = obj.characterReplacement(s, k);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends