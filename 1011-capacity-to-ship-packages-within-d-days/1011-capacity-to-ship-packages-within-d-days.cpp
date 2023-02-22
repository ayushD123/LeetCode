class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int low=*max_element(weights.begin(),weights.end());
        int high=0;
        for(auto it:weights){
            high+=it;
        }
        int ans=0;
        for(int cap=low;cap<=high;++cap){
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
                ans=cap;
                break;
            }
        }
        return ans;
    }
};