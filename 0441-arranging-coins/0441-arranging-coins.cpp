class Solution {
public:
    int arrangeCoins(int n) {
     //   vector<int> v(n+1,0);
       int low=0;
        int high=n;
        int ans=0;
        while(low<=high){
            int mid=(low+high)/2;
            long long k=((long long)mid*(mid+1)/2);
            if(k<=n){
                ans=mid;
                low=mid+1;
            }else{
                high=mid-1;
            }
        }
        return ans;
    }
};