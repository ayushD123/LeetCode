class Solution {
public:
    int minDeletionSize(vector<string>& str) {
          int ans=0;
        for(int i=0;i<str[0].length();++i){
            string s;
            for(int j=0;j<str.size();++j){
                s.push_back(str[j][i]);
            }
            if(s.length()<2){
                continue;
            }
            string t=s;
           sort(t.begin(),t.end());
            if(t!=s){
                ans++;
            }else{
                continue;
            }
        }
        return ans;
    }
};