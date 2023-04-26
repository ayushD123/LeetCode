class Solution {
public:
    int addDigits(int num) {
        string s=to_string(num);
        while(s.size()>1){
            int a=0;
            for(int i=0;i<s.size();++i){
                a+=int(s[i]-'0');
            }
            //cout<<a<<endl;
            s=to_string(a);
        }
        return stoi(s);
    }
};