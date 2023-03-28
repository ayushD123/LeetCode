class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int i=0;
        int j=1;
        int cnt=0;
        for(j=1;j<nums.size();++j){
            if(nums[i]!=nums[j]){
                nums[i+1]=nums[j];
                i++;
                cnt++;
            }
        }
        //cout<<cnt;
        return cnt+1;
    }
};