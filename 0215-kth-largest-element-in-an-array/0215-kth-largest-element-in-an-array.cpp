class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
      sort(nums.begin(),nums.end());
        int i=0;
        for(auto it:nums){
          //  cout<<i<<endl;
            if(i==(nums.size()-k)){
                return it;
            }
            i++;
        }
        return -1;
    }
};