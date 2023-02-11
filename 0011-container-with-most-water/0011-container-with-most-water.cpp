class Solution {
public:
    int maxArea(vector<int>& height) {
        int lp=0;
        int rp=height.size()-1;
       int n=height.size()-1;
        int ans=(min(height[lp],height[rp])*(rp));
        while(lp<rp){
            if(height[lp]<height[rp]){
                lp++;
            }else{
                rp--;
                }
                ans=max(ans,(min(height[lp],height[rp])*(rp-lp)));

        }
        return ans;
    }
};