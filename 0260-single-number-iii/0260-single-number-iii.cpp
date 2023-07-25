class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int xorres=0;
        vector<int> ans;
        for(auto it:nums){
            xorres^=it;
        }
        int pos=0;
            int i=0;
        int temp=xorres;
        while(1){
            if(temp&1){
                pos=i;
                break;
            }
            i++;
            temp=temp>>1;
        }
        temp=0;
        for(auto it:nums){
            if((it&(1<<pos))==0){
                temp^=it;
            }
        }
        
        ans.push_back(temp);
        ans.push_back(xorres^temp);
        return ans;
    }
};