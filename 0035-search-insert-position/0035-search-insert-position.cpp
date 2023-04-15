class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
       if(target<=nums[0]){
           return 0;
       }
        if(target>nums[nums.size()-1]){
            return nums.size();
        }
       int low=0;
        int high=nums.size()-1;
        int ans=0;
        while(low<=high){
            int mid=(high+low)/2;
            if(nums[mid]==target) return mid;
            if(nums[mid]>target){
                high=mid-1;
                ans=mid;
            }else{
                low=mid+1;
               // ans=mid;
            }
        }
        return ans;
    }
};