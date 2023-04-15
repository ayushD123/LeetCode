class Solution {
public:
    int minCapability(vector<int>& nums, int k) {
        int low=1;
         int high=1e9;
        int ans=1e9+7;
        while(low<=high){
            int mid=(low+high)/2;
            int cnt=0;
            for(int i=0;i<nums.size();++i){
                if(nums[i]<=mid){
                    cnt++;
                    i++;
                }
            }
            if(cnt>=k){
                ans=min(ans,mid);
                high=mid-1;
            }else{
                low=mid+1;
            }
        }
        return ans;
    }
};