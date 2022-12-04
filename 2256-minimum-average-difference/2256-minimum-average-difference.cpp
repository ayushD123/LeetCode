class Solution {
public:
    int minimumAverageDifference(vector<int>& nums) {
        long long  pref[1000009]={0};
        pref[0]=nums[0];
        for(int i=1;i<nums.size();++i){
            pref[i]=pref[i-1]+nums[i];
        }
        int ans=0;
        int min=99999;
        int n=nums.size();
        for(int i =0;i<nums.size();++i){
            long long lsum=pref[i];
            long long rsum=pref[n-1]-lsum;
            lsum=lsum/(i+1);
            if((n-i-1)==0){
                rsum=0;
            }else{
                rsum=rsum/(n-i-1);
            }
            long long temp=abs(lsum-rsum);
            if(temp<min){
                min=temp;
                ans=i;
            }
            
        }
        return ans;
    }
};