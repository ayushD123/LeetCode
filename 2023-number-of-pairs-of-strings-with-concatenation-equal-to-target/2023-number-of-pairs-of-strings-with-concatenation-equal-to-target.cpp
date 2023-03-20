class Solution {
public:
    int numOfPairs(vector<string>& nums, string target) {
        int cnt=0;
        for(int i=0;i<nums.size();++i){
            string it1=nums[i];
            for(int j=0;j<nums.size();++j){
                string it2=nums[j];
                if(i==j) continue;
                string s=it1+it2;
                if(s==target){
                    cnt++;
                }
            }
        }
        return cnt;
    }
};