class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char,int> mp;
        int left=0;
        int winsize=0;
        int ans=0;
        for(int right=0;right<s.length();){
            mp[s[right]]++;
            right++;
             winsize=right-left;
            while(left<=right && mp.size()!=winsize){
                mp[s[left]]--;
                if(mp[s[left]]==0){
                    mp.erase(s[left]);
                }
                left++;
                     winsize=right-left;
            }
            if(mp.size()==winsize){
                ans=max(ans,winsize);
            }
            }
            
        
        return ans;
    }
};