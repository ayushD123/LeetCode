class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int i=0;
        while(i<nums.size() && nums[i]<target){
            i++;
        }
        return i;
        // for(int i=0;i<nums.size();++i){
        //     if(nums[i]==target){
        //         return i;
        //     }
        // }
    }
};