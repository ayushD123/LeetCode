class Solution {
public:
    int equalSubstring(string s, string t, int maxCost) {
        int left=0;
        int right=0;
        int sum=0;
        int n=s.length();
        int ans=0;
        while(right<s.length()){
            int a=s[right]-'a';
            int b=t[right]-'a';
            int sx=abs(a-b);
            sum+=sx;
            while(left<=right && sum>maxCost){
            int x=(s[left]-'a');
            int y=t[left]-'a';
            int z=abs(x-y);
            sum-=z;
                left++;
            }
            ans=max(ans,right-left+1);
            right++;
        }
        return ans;
    }
};