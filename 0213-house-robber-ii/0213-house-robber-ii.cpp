// class Solution {
// public:
//     int space(vector<int> &nums){
//         int n=nums.size(); //n-2
//         int a=nums[0];  //n-1
//         int b=max(nums[0],nums[1]);
//         for(int i=2;i<n;++i){
//             int pick=nums[i]+a;
//             int npick=0+b;
//             int curr=max(pick,npick);
//             a=b;
//             b=curr;
//         } 
        
//         return b;
//     }
 
        
       
        
//     int rob(vector<int>& nums) {
//         if(nums.size()==1){
//             return nums[0];
//         }
//         vector<int> arr1;
//          vector<int> arr2;
//         for(int i=1;i<nums.size();++i){
//             arr1.push_back(nums[i]);
//         }
//           for(int i=0;i<nums.size()-1;++i){
//             arr2.push_back(nums[i]);
//         }
//         int ans1= space(arr1);
        
//         int ans2= space(arr2);
//         return max(ans1,ans2);
//     }
// };

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
         vector<int> arr1;
         vector<int> arr2;
       for(int i=1;i<nums.size();++i){
            arr1.push_back(nums[i]);
        }
          for(int i=0;i<nums.size()-1;++i){
            arr2.push_back(nums[i]);
        }
        int ans1 = space(arr1);
        int ans2 = space(arr2);
        
        return max(ans1, ans2);
    }
};
