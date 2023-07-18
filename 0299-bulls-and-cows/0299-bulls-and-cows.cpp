class Solution {
public:
    string getHint(string secret, string guess) {
        int x=0;
        unordered_map<char,int> mp1;
        unordered_map<char,int> mp2;
        string ans="";
        for(int i=0;i<guess.size();++i){
            if(secret[i]==guess[i]){
                x++;
            }
            mp1[guess[i]]++;
            mp2[secret[i]]++;
        }
         char c = (char(x)+0);
        ans+=to_string(x);
        
        int cnt=0;
     for(auto it:mp1){
         cnt+=min(it.second,mp2[it.first]);
     }
        ans+='A';
        int y=cnt-x;
        ans+=to_string(y);
        ans+='B';
        return ans;
        
        
    }
};