class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char,int> mp;
        int left=0;
        int winsize=0;
        int ans=0;
        for(int right=0;left<s.length() && right<s.length();){
            mp[s[right]]++;
            right++;
             winsize=right-left;
            
            if(winsize==mp.size()){
               ans=max(ans,winsize); 
            }else{
                 while(left<s.length() && winsize>0 && mp.size()!=winsize){
                mp[s[left]]--;
                if(mp[s[left]]==0){
                    mp.erase(s[left]);
                }
                left++;
                     winsize=right-left;
            }
            }
            
        }
        return ans;
    }
};