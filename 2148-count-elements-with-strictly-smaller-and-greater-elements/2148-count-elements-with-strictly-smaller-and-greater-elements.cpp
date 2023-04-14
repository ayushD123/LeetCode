class Solution {
public:
    int countElements(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int i=0;
        int j=nums.size()-1;
        if(nums.size()==1) return 0;
        while(i<(nums.size()-1) && nums[i]==nums[i+1]){
            i++;
        }
         while(j>=1 && j>=i && nums[j]==nums[j-1]){
            j--;
        }
        if(j<i) return 0;
        return j-i-1;
        
    }
};