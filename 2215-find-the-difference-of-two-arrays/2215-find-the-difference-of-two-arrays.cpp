class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        unordered_set st1(nums1.begin(),nums1.end());
        unordered_set st2(nums2.begin(),nums2.end());
        vector<vector<int>> ans;
        vector<int> v;
        for(auto it:st1){
            
            if(st2.find(it)==st2.end()){
                v.push_back(it);
            }
        }
        ans.push_back(v);
        vector<int> v1;
        for(auto it:st2){
            
            if(st1.find(it)==st1.end()){
                v1.push_back(it);
            }
        }
        ans.push_back(v1);
        return ans;
    }
};