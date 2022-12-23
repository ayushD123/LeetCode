class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        
       int minprice=9999;
        int maxprof=-1;
    for(int i=0;i<n;++i){
        if(prices[i]<minprice){
            minprice=prices[i];
        }
        int prof=prices[i]-minprice;
        if(prof>maxprof){
            maxprof=prof;
        }
    }
        return maxprof;
    }
};