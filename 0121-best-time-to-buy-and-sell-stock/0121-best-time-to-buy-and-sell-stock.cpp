class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int msf=0;
        vector<int> v;
        int n=prices.size();
        for(int i=n-1;i>=0;i--){
            if(prices[i]>msf){
                msf=prices[i];
                
            }
            v.push_back(msf);
             
            }
        reverse(v.begin(), v.end());
        for(auto it:v){
            cout<<it<<" ";
        }
        
        int ans=0;
        for(int i=0;i<n;++i){
            if(v[i]-prices[i]>ans){
                ans=v[i]-prices[i];
            }
        }
        return ans;
        
    }
};