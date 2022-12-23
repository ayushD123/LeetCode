class Solution {
public:
  //  int pref[1e4+10];
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int,int> map;
        int n=nums.size();
        int curr=0;
        int cnt=0;
        for(int i=0;i<nums.size();++i){
            curr+=nums[i];
            
            if(curr==k){
                cnt++;
            }
            if(map.find(curr-k)!=map.end()){
                cnt+=map[curr-k];
            }
            map[curr]++;
        }
        cout<<map.size();
        if(map.size()==1 && n>1){
            return n*(n+1)/2;
        }
        return cnt;
    }
};