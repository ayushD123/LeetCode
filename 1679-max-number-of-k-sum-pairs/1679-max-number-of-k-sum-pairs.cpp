class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        unordered_map<int,int> mp;
        int ans=0;
        for(auto it:nums){
            int a=k-it;
            if(mp[a]!=0){
                ans++;
              //  cout<<a<<" ";
                mp[a]--;
            }else{
                mp[it]++;
            }
        }
        return ans;
    }
};