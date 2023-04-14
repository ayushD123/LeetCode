class Solution {
public:
    int arrangeCoins(int n) {
     //   vector<int> v(n+1,0);
        int ans=0;
        
        int i=1;
        int j=1;
        while(n>=1){
            i=j;
            i-=n;
             n-=j;
            if(i<=0) ans++;
            j++;
           
        }
       
        return ans;;
    }
};