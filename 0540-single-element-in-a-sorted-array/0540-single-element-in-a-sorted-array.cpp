class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
       int low=0;
    int high=nums.size()-1;
        while(low<high){
            int mid=(low+high)/2;
            if(mid%2==0){
                if(nums[mid]==nums[mid+1]){
                    low=mid+1;;
                }else{
                    high=mid; //because mid could be possible ans hence cant exclude by mid-1
                }
            }else{
                if(nums[mid]==nums[mid-1]){
                    low=mid+1;
                }else{
                    high=mid;
                }
            }
        }
        return nums[low];
    }
};
    