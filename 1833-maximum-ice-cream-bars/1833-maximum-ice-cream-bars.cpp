class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
       sort(costs.begin(),costs.end());
        int ans=0;
        int rem=0;
        for(auto it:costs){
            if((rem+it)<=coins){
                rem+=it;
                ans++;
            }else{
                break;
            }
        }
        return ans;
    }
};