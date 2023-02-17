class Solution {
public:
    int characterReplacement(string s, int k) {
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