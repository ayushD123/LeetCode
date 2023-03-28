class Solution {
public:
    int numberOfSubstrings(string s) {
        unordered_map<char,int> mp;
        int left=0;
        int right=0;
        int ans=0;
        int n=s.length();
        while(right<n){
            char c=s[right];
            mp[c]++;
            right++;
            while(left<n && mp.size()>=3){
                ans+=n-right+1;
                char b=s[left];
                mp[b]--;
                if(mp[b]==0){
                    mp.erase(b);
                }
                left++;
            }
        }
        return ans;
    }
};