class Solution {
public:
    void solve(vector<vector<int>> &ans,vector<int> op,int index,vector<int> nums){
        if(index>=nums.size()){
            ans.push_back(op);
            return;
        }
        op.push_back(nums[index]);
        solve(ans,op,index+1,nums);
        op.pop_back();
       solve(ans,op,index+1,nums);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> op;
        solve(ans,op,0,nums);
        return ans;
    }
};