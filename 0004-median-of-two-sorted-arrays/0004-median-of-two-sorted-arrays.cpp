class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        for(auto it:nums2){
            nums1.push_back(it);
        }
        sort(nums1.begin(),nums1.end());
        int n=nums1.size();
        if(n%2!=0){
            double ans=nums1[n/2];
            return ans;
        }else{
            double ans=(double)(nums1[n/2]+nums1[(n/2)-1])/2;
            return ans;
        }
    }
};