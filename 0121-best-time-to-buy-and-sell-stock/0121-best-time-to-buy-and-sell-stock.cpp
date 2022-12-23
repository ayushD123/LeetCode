class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        
       int maxprice=0;
        int maxprof=-1;
    for(int i=n-1;i>=0;i--){
        if(prices[i]>maxprice){
            maxprice=prices[i];
        }
        int prof=maxprice-prices[i];
        if(prof>maxprof){
            maxprof=prof;
        }
    }
        return maxprof;
    }
};