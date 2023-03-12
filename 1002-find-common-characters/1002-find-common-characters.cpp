class Solution {
public:
    vector<string> commonChars(vector<string>& words) {
        if(words.size()==1){
            return words;
        }
        unordered_map<char,int> mp;
        for(char c:words[0]){
            mp[c]++;
        }
        vector<int> minfreq(26,1e4);
        
        for(int i=1;i<words.size();++i){
            string it=words[i];
            unordered_map<char,int> freq;
            for(auto x:it){
                freq[x]++;
            }
            for(char c='a';c<='z';c++){
                mp[c]=min(mp[c],freq[c]);
            }
            
        }
        vector<string> ans;
        for(auto it:mp){
            while(it.second>0){
                string s;
                s+=it.first;
                ans.push_back(s);
                it.second--;
            }
        }
                    
        return ans;                                
    }
};