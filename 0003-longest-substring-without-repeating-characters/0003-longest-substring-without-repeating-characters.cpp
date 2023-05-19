class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char,int> mp;
       int left=0;
        int right=0;
        int ans=0;
        int n=s.length();
        while(right<n){
            mp[s[right]]++;
        int winsize=right-left+1;
        while(left<right && mp.size()!=winsize){
            mp[s[left]]--;
            if(mp[s[left]]==0) mp.erase(s[left]);
            left++;
            winsize=right-left+1;
        }
        ans=max(winsize,ans); 
            right++;
        }
       return ans;
    }
};