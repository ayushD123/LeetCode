class Solution {
public:
    int characterReplacement(string s, int k) {
        unordered_map<char,int> mp;
        int right=0;
        int left=0;
        int maxfreq=0;
        int maxlen=0;
        int n=s.length();
        while(right<n){
            mp[s[right]]++;
            maxfreq=max(maxfreq,mp[s[right]]);
            if(((right-left+1)-maxfreq)<=k){
                maxlen=max(maxlen,right-left+1);
                right++;
                
            }else{
                while((right-left+1)-maxfreq>k){
                    mp[s[left]]--;
                    left++;
                }
                right++;
            }
        }
        return maxlen;
    }
};