class Solution {
public:
    int space(vector<int> &nums){
        int n = nums.size();
     //   if (n == 0) return 0; // Handle empty vector
        if (n == 1) return nums[0];
        
        int a = nums[0];
        int b = max(nums[0], nums[1]);
        
        for(int i = 2; i < n; ++i){
            int pick = nums[i] + a;
            int npick = b;
            int curr = max(pick, npick);
            a = b;
            b = curr;
        } 
        
        return b;
    }
   
    int rob(vector<int>& nums) {
        int n = nums.size();
        
     //   if (n == 0) return 0;
        if (n == 1) return nums[0];
        
        vector<int> arr1(nums.begin() + 1, nums.end());
        vector<int> arr2(nums.begin(), nums.end() - 1);
        
        int ans1 = space(arr1);
        int ans2 = space(arr2);
        
        return max(ans1, ans2);
    }
};
