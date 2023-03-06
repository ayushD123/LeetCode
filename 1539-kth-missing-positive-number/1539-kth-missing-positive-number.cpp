class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        vector<int> hash(10005,0);
        for(auto it:arr){
            hash[it]=1;
        }
        int cnt=0;
        for(int i=1;i<10005;++i){
           // cout<<hash[i]<<" ";
            if(hash[i]==0){
                cnt++;
            }
            if(cnt==k){
                return i;
            }
        }
        return -1;
        
    }
};