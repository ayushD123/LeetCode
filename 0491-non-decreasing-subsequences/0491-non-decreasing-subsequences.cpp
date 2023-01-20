class Solution {
public:
    void subseq(int ind,set<vector<int>> &ans,vector<int> nums,int n,vector<int> temp){
        if(ind==n){
            vector<int> a;
            if(temp.size()>=2){
               ans.insert(temp);
            }
          //  ans.insert(a);
            return;
        }
         if(temp.size()==0 || temp.back() <= nums[ind]){
             temp.push_back(nums[ind]);
          
       
         }
         subseq(ind+1,ans,nums,n,temp);
       
        temp.pop_back();
         subseq(ind+1,ans,nums,n,temp);
        
    }
    
    vector<vector<int>> findSubsequences(vector<int>& nums) {
       
        set<vector<int>> st;
       
        int n=nums.size();
        vector<int> temp;
        subseq(0,st,nums,n,temp);
        vector<vector<int>> ans(st.begin(),st.end());
      //   for(auto it:st){
      //       ans.push_back(it);
      //   }
      // /
        return ans;
    }
};