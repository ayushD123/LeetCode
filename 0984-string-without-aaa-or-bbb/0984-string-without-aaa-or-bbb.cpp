class Solution {
public:
    string strWithout3a3b(int a, int b) {
        int cnta=0;
        int cntb=0;
        string ans="";
        int n=a+b;
        while(n--){
            if((a>=b && cnta<2) || (cntb==2 && a>0)){
                ans+='a';
                cnta++;
                a--;
                cntb=0;
            }else
            if((b>=a && cntb<2) || (cnta==2 && b>0)){
                ans+='b';
                cntb++;
                b--;
                cnta=0;
            }
            
        }
        return ans;
    }
};