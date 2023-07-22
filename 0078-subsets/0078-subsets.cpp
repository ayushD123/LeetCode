class Solution {
public:
    vector<int> subst(int num,vector<int> &v,int n){
        vector<int> t;
        int j=0;
        while(num){
            if(num & 1){
                t.push_back(v[j]);
            }
            j++;
            num=num>>1;
        }
        return t;
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>> ans;
        for(int i=0;i<(1<<n);++i){
            ans.push_back(subst(i,nums,n));
        }
        return ans;
    }
};