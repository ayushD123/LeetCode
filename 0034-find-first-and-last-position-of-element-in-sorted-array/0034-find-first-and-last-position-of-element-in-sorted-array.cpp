class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int l=-1,r=-1;
        for(int i=0;i<nums.size();++i){
            if(nums[i]==target && l==-1){
                l=i;
                r=i;
            }else
             if(nums[i]==target && l!=-1){
                r=i;
            }
        }
        
            return {l,r};
    }
};