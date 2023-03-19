class Solution {
public:
    int distMoney(int money, int ch) {
       if(ch>money){
           return -1;
           }
        vector<int> v(ch,1);
        money-=ch;
        for(int i=0;i<ch;++i){
            if(money>=7){
                v[i]+=7;
                money-=7;
            }else{
                if(money==3){
                    if(i==ch-1){
                        v[i]+=2;
                        v[i-1]+=1;
                    }else{
                        v[i]+=2;
                        v[i+1]+=1;
                    }
                }
            }
        }
        if(money){
            v[ch-1]+=money;
        }
        int cnt=0;
        for(auto it:v){
            if(it==8){
                cnt++;
            }
        }
        return cnt;
    }
};