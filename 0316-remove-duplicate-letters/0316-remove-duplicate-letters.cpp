class Solution {
public:
    string removeDuplicateLetters(string s) {
        unordered_map<char,int> mp;
        unordered_map<char,bool> mpb;
       stack<char> st;
        for(auto it:s){
            mp[it]++;
            mpb[it]=false;
        }
        st.push(s[0]);
        mpb[s[0]]=1;
        mp[s[0]]--;
        for(int i=1;i<s.length();++i){
            char x=s[i];
            
            if(mpb[x]){
                mp[x]--;
                continue;
            }
            while(!st.empty() && x<st.top() && mp[st.top()]>0){
                mpb[st.top()]=0;
                st.pop();
            }
            st.push(x);
            mpb[st.top()]=1;
            mp[x]--;
        }
        string ans="";
        while(!st.empty()){
            ans+=st.top();
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};