class Solution {
public:
    int maxProfit(vector<int>& prices) {
       // int buy=9999;
       //  int prof=0;
       //  for(int i=0;i<prices.size();++i){
       //      if(prices[i]<buy){
       //          buy=prices[i];
       //      }
       //      if(prices[i]-buy>prof){
       //          prof=prices[i]-buy;
       //      }
       //  }
       //  return prof;
        int sell=-1;
        int prof=0;
        for(int i=prices.size()-1;i>=0;i--){
            if(prices[i]>sell){
                sell=prices[i];
            }
            if(sell-prices[i]>prof){
                prof=sell-prices[i];
            }
        }
        return prof;
    }
};