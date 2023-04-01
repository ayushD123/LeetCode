class Solution {
public:
    int equalSubstring(string s, string t, int k) {
        vector<int> v;
        int n=s.length();
        for(int i=0;i<s.length();++i){
            int a=abs(s[i]-t[i]);
            v.push_back(a);
        }
        // for(auto it:v){
        //     cout<<it<<" ";
        // }
      
        int left=0;
        int right=0;
        int ans=0;
        int sum=0;
        while(left <n && right<n){
           while(right<n && (v[right]+sum)<=k){
               sum+=v[right];
               right++;
               
           }
            ans=max(ans,right-left);
            sum-=v[left];
            left++;
        }
        return ans;
    }
};