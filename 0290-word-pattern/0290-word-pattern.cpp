class Solution {
public:
    bool wordPattern(string p, string s) {
        unordered_map<char,vector<int>> mp1;
       for(int i=0;i<p.length();++i){
           mp1[p[i]].push_back(i);
       }
        
        unordered_map<string,vector<int>> mp2;
        vector<string> st;
         for(int i=0;i<s.length();++i){
             int j=i;
             string a;
             while(j<s.length() && s[j]!=' '){
                 a.push_back(s[j]);
                 j++;
             }
            
             i=j;
             st.push_back(a);
             
             
         }
         for(int i=0;i<st.size();++i){
           mp2[st[i]].push_back(i);
       }
        
        
        if(mp1.size()!=mp2.size()){
            return false;
        }
        for(int i=0;i<mp2.size();++i){
            vector<int> a=mp1[p[i]];
            vector<int> b=mp2[st[i]];
            if(a!=b){
                return false;
            }
        }
        return true;
    }
};