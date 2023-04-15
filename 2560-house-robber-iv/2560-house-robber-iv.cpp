class Solution {
public:
    int minCapability(vector<int>& nums, int k) {
        int low=*min_element(nums.begin(),nums.end());
         int high=*max_element(nums.begin(),nums.end());
        int ans=INT_MAX;
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