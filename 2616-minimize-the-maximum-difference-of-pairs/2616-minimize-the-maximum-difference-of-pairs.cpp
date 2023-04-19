class Solution {
public:
    int minimizeMax(vector<int>& nums, int p) {
        int low=0;
        int high=1e9;
        int ans=0;
        sort(nums.begin(),nums.end());
        while(low<=high){
            int mid=(low+high)/2;
            int cnt=0;
            for(int i=0;i<nums.size()-1;++i){
                if(abs(nums[i]-nums[i+1])<=mid){
                    cnt++;
                    i++;
                }
            }
            if(cnt>=p){
                ans=mid;
                high=mid-1;
            }else{
                low=mid+1;
            }
        }
        return ans;
    }
};