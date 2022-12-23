class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        //approach 1-from left to right finding minimum buying price and checking profit if we sell it today
        /*
         
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
    */
        //approach 2-from right to left finding maximum selling price and checking profit if we sell it today
        
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
        
        
        
    
    //
    
        
    }
};