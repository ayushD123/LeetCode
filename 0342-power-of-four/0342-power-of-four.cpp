class Solution {
public:
    bool isPowerOfFour(int n) {
        
        int cnt=0;
        int pos=0;
        for(int i=31;i>=0;i--){
        int num=((n>>i) & 1);
            if(num){
                cnt++;
                pos=i;
            }
        if(cnt>1) return 0;
        }
        if(cnt && (pos%2==0)) return 1;
        return 0;
    }
};