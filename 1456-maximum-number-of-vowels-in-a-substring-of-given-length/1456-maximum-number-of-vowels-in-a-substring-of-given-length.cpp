class Solution {
public:
    bool isvowel(char c){
        if(c=='a' || c=='e' || c=='i' || c=='u' || c=='o'){
            return true;
        }
        return false;
    }
    int maxVowels(string s, int k) {
        unordered_map<char,int> mp;
        int n=s.length();
        int cnt=0;
        int left=0;
        int right=0;
        int ans=0;
     while(right<n){
         if(right<k){
             mp[s[right]]++;
             if(isvowel(s[right])){
                 cnt++;
             }
             right++;
             ans=max(ans,cnt);
         }else{
             
             mp[s[left]]++;
             if(isvowel(s[left])){
                 cnt--;
             }
             left++;
             if(isvowel(s[right])){
                 cnt++;
             }
             right++;
             ans=max(ans,cnt);
         }
         
     }   
        return ans;
    }
};