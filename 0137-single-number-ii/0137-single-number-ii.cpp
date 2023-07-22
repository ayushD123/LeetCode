class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int result=0;
        for(int i=31;i>=0;i--){
            int sum=0;
            for(auto it:nums){
                sum=sum+(1 & (it>>i));
            }
            if(sum%3==1){
                result=result | (1<<(i));
            }
        }
        return result;
    }
};