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
                    v[i]+=2;
                  if(i==ch-1){
                      v[0]+=1; //need to incremnt money of any(here i took 0) person by 1(all the person before i have exatly 8 rupee so to distrubute all money and saving i from getting exaactly 4 we need to make someone getting 9 rupee)
                    
//                   }else{
                     
//                       v[i+1]+=1;
                      }
                    
//                 }else{
//                     v[i]+=money;
                   
                }
                 money=0;
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