class Solution {
public:
    int search(vector<int>& nums, int target) {
        int low=0;
        int high=nums.size()-1;
       
        while(low<=high){
            int mid=(low+high)/2;
            if(nums[mid]==target){
                return mid;
            }
           if(nums[mid]>=nums[0]){
               if(target<nums[0] || nums[mid]<target){
                   low=mid+1;
               }else{
                   high=mid-1;
               }
           }else{
               if(target>nums[nums.size()-1] || nums[mid]>target){
                   high=mid-1;
               }else{
                   low=mid+1;
               }
           }
        }
        return -1;
    }
};