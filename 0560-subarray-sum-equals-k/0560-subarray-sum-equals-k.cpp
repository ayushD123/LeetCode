class Solution {
public:
  //  int pref[1e4+10];
    int subarraySum(vector<int>& Arr, int K) {
        int ans=0;
        int N=Arr.size();
        unordered_map<int,int> mp;
        int pre=0;
        for(int i=0;i<N;++i){
            pre+=Arr[i];
            if(pre==K){
                ans++;
                
                
            }
          //  if(mp.find(pre-K)!=mp.end()){
                ans+=mp[pre-K];
            //    mp[pre]++;
           // }else{
                mp[pre]++;
           // }
        }
        return ans;
    }
};