class Solution {
public:
    typedef long long ll;
    bool canArrange(vector<int>& A, int K) {
        unordered_map<int,int> mp;
        for(auto it:A){
            int rem=((it%K)+K)%K;
            mp[rem]++;
        }
        for(auto it:mp){
            int rem=it.first;
            
            int req=K-it.first;
            if(rem==0){
                if(mp[rem]%2!=0) return false;
            }else if(mp.find(req)==mp.end()){
                return false;
            } else if(mp[rem]!=mp[req]){
                return false;
            }
        }
        return true;
    }
};