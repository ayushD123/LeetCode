class Solution {
public:
    int minimizeXor(long long num1, long long num2) {
        int ans=0;
        int c=__builtin_popcount(num2);
       for(int i=62;i>=0;i--){
            long long x=num1>>i;
            if(x&1 && c){
                
                ans=ans|(1<<i);
                c--;
            }
        }
     //   cout<<c;
        
        for(int i=0;i<62 && c>0;++i){
            if(ans & (1<<i)){

            }else{
                ans=ans|(1<<i);
                c--;
            }
        }
        return ans;
    }
};