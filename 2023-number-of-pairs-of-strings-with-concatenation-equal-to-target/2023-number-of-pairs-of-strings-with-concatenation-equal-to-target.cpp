class Solution {
public:
    int numOfPairs(vector<string>& nums, string target) {
        unordered_map<string,int> mp;
        for(auto it:nums){
            mp[it]++;
        }
        int cnt=0;
        for(int i=0;i<target.size();++i){
            string pre=target.substr(0,i);
            string suf=target.substr(i,target.size());
            if(suf==pre){
                cnt+=mp[suf]*(mp[pre]-1);
            }else{
                cnt+=mp[suf]*mp[pre];
            }
        }
        return cnt;
    }
};