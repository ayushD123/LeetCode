class Solution {
public:
    double helper(double x,long long n){
        if(n==0) return 1;
        if(n<0){
            return 1.0/helper(x,-1*n);
        }
    double sub=helper(x,n/2);
    double sq=sub*sub;
    if(n&1){
        return x*sq;
    }
        return sq;
    }
    
    double myPow(double x, int n) {
        return helper(x,(long long)n);
    }
};