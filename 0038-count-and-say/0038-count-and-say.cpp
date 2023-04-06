class Solution {
public:
    string countAndSay(int n) {
      //  int x=n;
        if(n==1) return "1";
        if(n==2) return "11";
        if(n==3) return "21";
        if(n==4) return "1211";
        string temp="1211";
        int t=n-4;
        while(t--){
            int cnt=1;
            string s="";
            temp+='&';
            for(int j=0;j<temp.size()-1;++j){
                if(temp[j]!=temp[j+1]){
                
                    s+=to_string(cnt);
                    s+=temp[j];
                    cnt=1;
                }else{
                    cnt++;
                }
            }
            temp=s;
        }
        return temp;
    }
};