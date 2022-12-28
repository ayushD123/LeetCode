class Solution {
public:
    int minStoneSum(vector<int>& piles, int k) {
      map<int,int,greater<int>> freq;
        int sum=0;
        int count=0;
        for(int pile:piles){
            freq[pile]++;
            sum+=pile;
        }
        
        for(int i=0;i<k;++i){
            int maxele=freq.begin()->first;
            count+=maxele/2;
            freq[maxele]--;
            if(freq[maxele]==0){
                freq.erase(freq.begin());
            }
            freq[maxele-(maxele/2)]++;
        }
        // int ans=0;
        // for(auto it:freq){
        //     ans+=it.first*it.second;
        // }
        // return ans;
        return sum-count;
    }
};