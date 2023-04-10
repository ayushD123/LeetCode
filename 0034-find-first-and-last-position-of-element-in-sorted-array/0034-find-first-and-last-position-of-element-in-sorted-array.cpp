class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int first=-1;
        int last=-1;
     //   if(nums.size()==0) return {-1,-1};
        int i=0;
        int j=nums.size()-1;
        while(i<=j){
            int mid=(i+j)/2;
         //   cout<<mid<<endl;
            if(nums[mid]==target){
                first=mid;
                j=mid-1;
              //  cout<<i<<" "<<j<<endl;
            }else{
                if(nums[mid]<target){
                    i=mid+1;
                }else{
                    j=mid-1;
                }
            }
        }
         i=0;
        j=nums.size()-1;
         while(i<=j){
            int mid=(i+j)/2;
            if(nums[mid]==target){
                last=mid;
                i=mid+1;
            }else{
                if(nums[mid]<target){
                    i=mid+1;
                }else{
                    j=mid-1;
                }
            }
        }
        return {first,last};
    }
};