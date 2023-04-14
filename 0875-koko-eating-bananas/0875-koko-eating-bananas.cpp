class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int low=1;
        int high=*max_element(piles.begin(),piles.end());
        int ans=0;
        while(low<=high){
            int mid=(low+high)/2;
            long long cnt=0;
            for(auto it:piles){
                if(it%mid==0){
                    cnt+=(it/mid);
                }else{
                    int x=(it/mid)+1;
                     cnt+=x;
                }
                
             //  cout<<cnt<<endl;
            }
            if(cnt<=h){
                ans=mid;
                high=mid-1;
            }else{
                low=mid+1;
            }
        }
        return ans;
    }
};