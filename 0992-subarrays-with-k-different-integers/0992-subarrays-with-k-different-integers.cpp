class Solution {
public:
    
    int atmost(vector<int>& nums, int k){
        
        int mp[100005]={0};
        int left=0;
        int ans=0;
        int dist=0;
        for(int right=0;right<nums.size();++right){
            int c=nums[right];
            mp[c]++;
            if(mp[c]==1){
                dist++;
            }
            while(left<=right && dist>k){
                int x=nums[left];
                mp[x]--;
                if(mp[x]==0){
                    dist--;
                }
                left++;
            }
            ans+=right-left+1;
        }
        return ans;
    }
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return atmost(nums,k)-atmost(nums,k-1);
    }
};