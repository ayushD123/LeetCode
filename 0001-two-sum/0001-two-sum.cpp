class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> freq;
        for(int i=0;i<nums.size();++i){
             int x=target-nums[i];
            if(freq[x]!=0){
                return {freq[x]-1,i};
            }
            freq[nums[i]]=i+1;
           
        }
        return {0,99};
    }
};