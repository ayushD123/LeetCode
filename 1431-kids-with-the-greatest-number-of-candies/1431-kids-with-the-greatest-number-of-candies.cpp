class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int ex) {
        int max=*max_element(candies.begin(),candies.end());
        vector<bool> ans;
        for(auto it:candies){
            if((it+ex)>=max){
                ans.push_back(1);
            }else{
                ans.push_back(0);
            }
        }
        return ans;
    }
};