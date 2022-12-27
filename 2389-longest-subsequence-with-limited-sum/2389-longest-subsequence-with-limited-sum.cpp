class Solution {
public:
    vector<int> answerQueries(vector<int>& nums, vector<int>& queries) {
        // Get the prefix sum array of the sorted 'nums'.
       sort(nums.begin(),nums.end());
        int sum=0;
        int cnt=0;
        vector<int> ans;
        int i=0;
        for(auto it:queries){
            sum=0;
            i=0;
            cnt=0;
            while(sum<=it && i<nums.size()){
                sum+=nums[i];
                if(sum<=it){
                  cnt++; 
                    i++;
                }
            }
            ans.push_back(cnt);
        }
        return ans;
    }
};