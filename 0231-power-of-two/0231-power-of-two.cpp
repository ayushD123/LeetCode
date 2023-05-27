class Solution {
public:
    bool isPowerOfTwo(long long n) {
         if(n==0) return 0;
        long long x=(long long)n&(n-1);
        if(x) return 0;
        return 1;
        
    }
};