class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
     
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
               ans=mid+1;
            }
        }
        return ans;
    }
};