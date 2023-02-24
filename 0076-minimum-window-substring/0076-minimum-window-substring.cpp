class Solution {
public:
    string minWindow(string s, string t) {
        vector<int> ans{ -1, 0, 0 };
        unordered_map<char,int> tmp;
        for(auto it:t){
            tmp[it]++;
        }
        unordered_map<char,int> wmp;
        int req=tmp.size();
        int formed=0;
        int l=0;
        int r=0;
        while(r<s.size()){
            char c=s[r];
            wmp[c]++;
            if(t.find(c)!=string::npos && wmp[c]==tmp[c]){ //
                formed++;
            }
            while(l<=r && formed==req){
                c=s[l];
                if(ans[0]==-1 || r-l+1<ans[0]){
                    ans[0]=r-l+1;
                    ans[1]=l;
                    ans[2]=r;
                }
                wmp[c]--;
                 if(t.find(c)!=string::npos && wmp[c]<tmp[c]){
                formed--;
            }
                l++;
            }
            r++;
        }
        // cout<<l<<" "<<r<<endl;
        // cout<<ans[1]<<" "<<ans[2]<<endl;
        return ans[0] == -1 ? "" : s.substr(ans[1], ans[2]-ans[1]+1);
    }
};