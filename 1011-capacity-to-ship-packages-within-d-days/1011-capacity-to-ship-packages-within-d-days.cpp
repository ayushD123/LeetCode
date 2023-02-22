class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int low=*max_element(weights.begin(),weights.end());
        int high=0;
        for(auto it:weights){
            high+=it;
        }
        int ans=1e5+10;
        // for(int cap=low;cap<=high;++cap){
        //   int dd=1;
        //   int sum=0;
        //     for(auto it:weights){
        //         sum+=it;
        //         if(sum>cap){
        //             dd++;
        //             sum=it;
        //         }
        //     }
        //     if(dd<=days){
        //         ans=cap;
        //         break;
        //     }
        // }
        while(low<=high){
            int cap=low + (high-low)/2;
             int dd=1;
          int sum=0;
            for(auto it:weights){
                sum+=it;
                if(sum>cap){
                    dd++;
                    sum=it;
                }
            }
            if(dd<=days){
                high=cap-1;
                ans=min(ans,cap);
                
            }else{
                low=cap+1;
              
            }
            
        }
        return low;
    }
};