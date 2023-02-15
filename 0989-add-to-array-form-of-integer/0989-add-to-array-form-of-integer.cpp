class Solution {
public:
    vector<int> addToArrayForm(vector<int>& num, int k) {
       int i=num.size()-1;
       vector<int> ans;
    //reverse(num.begin(),num.end());
        int cur=k;
        
        while(i>=0 || cur>0){
            if(i>=0)
            cur+=num[i];
            ans.push_back(cur%10);
           // num[i]=cur%10;
            cur/=10;
            i--;
        }
       
        reverse(ans.begin(),ans.end());
        return ans;
        
    }
};