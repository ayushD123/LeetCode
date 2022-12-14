class Solution {
public:
    int minimumAverageDifference(vector<int>& nums) {
        long long  pref[1000009]={0};
        long long sum=0;
        pref[0]=nums[0];
        for(int i=0;i<nums.size();++i){
            sum+=nums[i];
        }
        int ans=0;
        int min=99999;
        int n=nums.size();
        long long lsum=0;
        for(int i =0;i<nums.size();++i){
            lsum+=nums[i];
            long long rsum=sum-lsum;
            int a=lsum/(i+1);
            if((n-i-1)==0){
                rsum=0;
            }else{
                rsum=rsum/(n-i-1);
            }
            long long temp=abs(a-rsum);
            if(temp<min){
                min=temp;
                ans=i;
            }
            
        }
        return ans;
    }
};