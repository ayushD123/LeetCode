class Solution {
public:
    string restoreString(string s, vector<int>& indices) {
        vector<char> c(s.length());
        int i=0;
        for(auto it:indices){
            int ind=it;
            char k=s[i];
            c[ind]=k;
            i++;
        }
        i=0;
        for(auto it:c){
            s[i]=it;
            i++;
        }
        return s;
    }
};