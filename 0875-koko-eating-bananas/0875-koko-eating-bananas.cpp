class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int low=0;
        int high=*max_element(piles.begin(),piles.end());
        int ans=1e9;
        if(piles.size()==1){
            if(piles[0]%h==0){
                return piles[0]/h;
            }
            return (piles[0]/h + 1);
        }
        while(low<=high){
            int mid=low+(high-low)/2;
            if(mid==0) break;
            int sum=0;
            int k=0;
            int rem=0;
            for(auto it:piles){
                 
               if(it%mid==0){
                 k+=it/mid;  
               }else{
                   k+=((it/mid)+1);
               }
                  
            }
           // cout<<mid<<" "<<k<<endl;
            if(k<=h){
                high=mid-1;
                ans=min(ans,mid);
            }else{
                low=mid+1;
            }
            
        }
        return ans;
    }
};