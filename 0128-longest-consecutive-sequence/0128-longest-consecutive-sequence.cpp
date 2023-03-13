class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.size()<=1){
            return nums.size();
        }
        int cnt=0;
        int ans=0;
        sort(nums.begin(),nums.end());
        for(int i=0;i<nums.size()-1;++i){
            if(nums[i]==(nums[i+1]-1)){
               // cout<<"hi";
             cnt++;   
            }else if(nums[i]==nums[i+1]){
            
                continue;
            }else{
               //cout<<ans<<" "<<cnt;
               ans=max(ans,cnt);
                cnt=0;
                
            }
            
        }
        ans=max(ans,cnt);
        
        return ans+1;
    }
};