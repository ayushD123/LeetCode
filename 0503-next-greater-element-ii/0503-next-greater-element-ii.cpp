class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
     vector<int> tmp=nums;
        for(auto it:nums){
            tmp.push_back(it);
        }
        stack<int> st;
        vector<int> ans(tmp.size(),-1);
        for(int i=tmp.size()-1;i>=0;i--){
            while(!st.empty() && st.top()<=tmp[i]){
                st.pop();
            }
            if(!st.empty()) ans[i]=st.top();
            st.push(tmp[i]);
        }
        for(int i=0;i<nums.size();++i){
            ans.pop_back();
        }
        return ans;
    }
};