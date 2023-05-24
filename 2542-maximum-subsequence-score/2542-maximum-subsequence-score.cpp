class Solution {
public:
    long long maxScore(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<pair<int,int>> v;
        for(int i=0;i<nums1.size();++i){
            v.push_back({nums2[i],nums1[i]});
            
        }
        sort(v.begin(),v.end(),greater<pair<int,int>>());
        priority_queue <int, vector<int>, greater<int> > pq;
        long long ans=0;
        long long sum=0;
        for(int i=0;i<k;++i){
            sum+=v[i].second;
             pq.push(v[i].second)    ;
            }
        ans=sum*v[k-1].first;
        for(int i=k;i<nums1.size();i++){
            int t=pq.top();
            pq.pop();
            sum-=t;
            pq.push(v[i].second);
            sum+=v[i].second;
            ans=max(ans,sum*v[i].first);
        }
        return ans;
    }
};