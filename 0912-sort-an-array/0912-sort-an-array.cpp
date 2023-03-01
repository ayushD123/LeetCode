class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        
        unordered_map<int,int> mp;
        int maxx=-1e9+10;
        int minn=1e9+10;
        for(auto it:nums){
            maxx=max(maxx,it);
            minn=min(minn,it);
            mp[it]++;
        }
        int j=0;
        for(int i=minn;i<=maxx;++i){
            if(mp[i]!=0){
                while(mp[i]>0){
                    nums[j++]=i;
                    mp[i]--;
                    
                }
            }
        }
        return nums;
    }
};