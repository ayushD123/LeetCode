class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
      sort(nums.begin(),nums.end());
        multiset<int> st;
        for(auto it:nums){
            st.insert(it);
        }
        int i=0;
        for(auto it:st){
          //  cout<<i<<endl;
            if(i==(nums.size()-k)){
                return it;
            }
            i++;
        }
        return -1;
    }
};