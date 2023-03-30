class Solution {
public:
    int balancedString(string s) {
        unordered_map<char,int> mp;
        for(auto it:s){
            mp[it]++;
            
        }
        int n=s.length();
        int k=s.length()/4;
        int ans=n;
        int left=0;
        int right=0;
        while(right<n){
            mp[s[right]]--;
            while(mp['W']<=k && mp['Q']<=k && mp['R']<=k && mp['E']<=k){
                mp[s[left]]++;
                ans=min(ans,right-left+1);
                left++;
                if(left>=n){
                    break;
                }
                    
            }
            right++;
        }
        return ans;
    }
};