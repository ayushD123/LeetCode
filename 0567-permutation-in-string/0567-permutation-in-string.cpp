class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        sort(s1.begin(),s1.end());
        if(s1.size()>s2.size()) return false;
        if(s1.size()==s2.size()){
            string a=s2;
            sort(a.begin(),a.end());
            if(a==s1) return true;
            return false;
        }
        int k=s1.size();
        for(int i=0;i<s2.size()-k+1;++i){
            string a=s2.substr(i,k);
          //  cout<<s1<<" "<<a<<endl;
            sort(a.begin(),a.end());
            if(s1==a){
                return true;
            }
        }
        return false;
    }
};