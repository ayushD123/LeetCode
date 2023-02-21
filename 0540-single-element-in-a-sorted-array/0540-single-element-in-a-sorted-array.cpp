class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int i=0;
       for(auto it:nums){
           i^=it;
       }
        return i;
        }
};
    