class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int F=-1;
        int L = -1;
        int i = 0;
        int j = nums.size()-1;
        
        while(i<=j)
        {
            if(nums[i]==target){
              F = i;
            }
            else i++;
            if(nums[j]==target) {
              L = j;}
            else j--;
            
         if(F!=-1 and L!=-1)    break;
        }
        vector<int>res = {F,L};
        return res;
    }
};