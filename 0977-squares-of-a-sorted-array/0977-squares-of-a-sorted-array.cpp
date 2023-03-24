class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        vector<int> ans(nums.size(),0);
        if(nums.size()==1){
            return {nums[0]*nums[0]};
        }
        int i=0;
        int j=nums.size()-1;
        int k=nums.size()-1;
        while(i<=j){
            int a=nums[i]*nums[i];
            int b=nums[j]*nums[j];
            if(a>b){
                ans[k]=a;
                i++;
            }else{
                ans[k]=b;
                j--;
            }
            k--;
        }
        return ans;
    }
};