class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        int pre=0;
        unordered_map<int,int> mp;
        for(int i=0;i<nums.size();++i){
            pre+=nums[i];
            if(pre%k==0 && i>=1){
                return true;
            }
            
            int mod=pre%k;
           // cout<<pre<<" "<<mod<<endl;
            if(mp.find(mod)!=mp.end()){
                int j=mp[mod];
                
                if(i-j>=2){
                  //  cout<<i<<" "<<j;
                    return true;
                }
            }else{
                mp[mod]=i;
            }
        }
        
        return false;
    }
};