class Solution {
public:
    void subseq(int ind,set<vector<int>> &ans,vector<int> nums,int n,vector<int> temp){
        if(ind==n){
            vector<int> a;
            if(temp.size()<2){
                return;
            }
            for(auto it:temp){
                a.push_back(it);
            }
            ans.insert(a);
            return;
        }
        subseq(ind+1,ans,nums,n,temp);
        if(temp.size()==0){
            temp.push_back(nums[ind]);
        }else if(nums[ind]>=temp.back()){
           temp.push_back(nums[ind]); 
        }
        
         subseq(ind+1,ans,nums,n,temp);
        temp.pop_back();
    }
    
    vector<vector<int>> findSubsequences(vector<int>& nums) {
       vector<vector<int>> ans;
        set<vector<int>> st;
        int n=nums.size();
        vector<int> temp;
        subseq(0,st,nums,n,temp);
        for(auto it:st){
            ans.push_back(it);
        }
        return ans;
    }
};