class Solution {
public:
    bool halvesAreAlike(string s) {
        int cnt1=0,cnt2=0;
        int i=0;
        for(i=0;i<s.length()/2;++i){
            char ch=tolower(s[i]);
            if(ch=='a' || ch=='e' || ch=='i' || ch=='o'|| ch=='u'){
               cnt1++;
               }
        }
                for(int j=i;j<s.length();++j){
            char ch=tolower(s[j]);
            if(ch=='a' || ch=='e' || ch=='i' || ch=='o'|| ch=='u'){
               cnt2++;
               }
        }
               if(cnt1==cnt2) return true;
               return false;
    }
};