class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int sell=prices[prices.size()-1];
        int profit=0;
       for(int i=prices.size()-1;i>=0;i--){
           sell=max(sell,prices[i]);
           profit=max(profit,sell-prices[i]);
       }
        return profit;
    }
};