class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
          unordered_map<int,int> map;
        int n=nums.size();
        if(n<2) return false;
        int curr=0;
        int cnt=0;
        map[0]=-1;
        for(int i=0;i<nums.size();++i){
            curr+=nums[i];
            curr=curr%k;
            
            // if(curr==k){
            //     cnt++;
            // }
            if(map.find(curr)!=map.end()){
                if(i-map[curr]>1)
                return true;
            }else{
                map[curr]=i; 
            }
           
        }
        // cout<<map.size();
        // if(map.size()==1 && n>1){
        //     return n*(n+1)/2;
        // }
        return false;
    
    }
};