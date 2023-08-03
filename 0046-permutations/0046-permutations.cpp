class Solution {
public:
    void recu(vector<int>&nums,vector<int> temp,vector<vector<int>> &ans,int ind){
        if(ind>=nums.size()){
            ans.push_back(temp);
            return;
        }
        for(int i=ind;i<nums.size();++i){
            swap(temp[ind],temp[i]);
            recu(nums,temp,ans,ind+1);
             swap(temp[ind],temp[i]);
            
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
          vector<vector<int>> ans;
                recu(nums,nums,ans,0);
        return ans;
    }
};