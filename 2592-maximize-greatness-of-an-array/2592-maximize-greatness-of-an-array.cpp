class Solution {
public:
    int maximizeGreatness(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<int> per=nums;
        int n=nums.size();
        int j=0;
        int ans=0;
        for(int i=0;i<n;++i){
            while(j<n && nums[i]>=per[j]) j++;
            if(j<n  && per[j]>nums[i]){
                ans++;
                j++;
            }
        }
        return ans;
    }
};