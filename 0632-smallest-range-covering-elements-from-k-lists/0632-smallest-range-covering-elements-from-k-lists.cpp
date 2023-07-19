class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
       priority_queue<vector<int>,vector<vector<int>>,greater<vector<int>>> pq;
        vector<int> ans={-1000000,1000000};
        int maxi=INT_MIN;
        int k=nums.size();
        for(int i=0;i<k;++i){
            maxi=max(maxi,nums[i][0]);
            pq.push({nums[i][0],0,i});
        }
        while(1){
            vector<int> min_node=pq.top();
            pq.pop();
            if(ans[1]-ans[0]>maxi-min_node[0]){
                ans[1]=maxi;
                ans[0]=min_node[0];
               
            }
             min_node[1]++;
            vector<int> t=nums[min_node[2]];
            if(min_node[1]==t.size()) break;
            min_node[0]=t[min_node[1]];
            maxi=max(maxi,min_node[0]);
            pq.push(min_node);
        }
        return ans;
    }
};