class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
     priority_queue<int> q(nums.begin(),nums.end());
        int a=1;
       while(q.size()!=0){
           if(a==k){
               return q.top();
           }
           a++;
           q.pop();
       }
        return -1;
        
    }
};