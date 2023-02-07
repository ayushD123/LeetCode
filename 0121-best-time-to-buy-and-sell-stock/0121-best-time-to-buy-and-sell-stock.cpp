class Solution {
public:
    int maxProfit(vector<int>& prices) {
       int buy=9999;
        int prof=0;
        for(int i=0;i<prices.size();++i){
            if(prices[i]<buy){
                buy=prices[i];
            }
            if(prices[i]-buy>prof){
                prof=prices[i]-buy;
            }
        }
        return prof;
    }
};