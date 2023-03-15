class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        unordered_map<string,int> mp;
        for(auto it:words){
            mp[it]++;
        }
        int ans=0;
            int flag=1;
        for(int i=0;i<words.size();++i){
            
            string s=words[i];
            string r="";
            r+=s[1];
            r+=s[0];
            if(r!=s){
                if(mp.find(r)!=mp.end()){
                    int cnt=min(mp[s],mp[r]);
                    ans+=cnt*4;
                    mp.erase(s);
                    mp.erase(r);
                }
            }else{
                int n=mp[s];
               // cout<<n<<" ";
                if(n%2==0){
                 //   cout<<"hi";
                    ans+=n*2;
                }else{
                    if(flag){
                        flag=0;
                        ans+=n*2;
                    }else{
                        ans+=(n-1)*2;
                    }
                    
                    
                }
                mp.erase(s);
            }
            
        }
        return ans;
    }
};