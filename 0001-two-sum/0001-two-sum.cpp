class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> freq;
        for(int i=0;i<nums.size();++i){
             int x=target-nums[i];
            if(freq.find(x)!=freq.end()){
                return {freq[x],i};
            }
            freq[nums[i]]=i;
           
        }
        return {0,99};
    }
};