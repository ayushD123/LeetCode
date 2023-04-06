class Solution {
public:
    string restoreString(string s, vector<int>& indices) {
       string t=s;
        int i=0;
        for(auto it:indices){
            t[it]=s[i];
            i++;
        }
        return t;
    }
};