class Solution {
public:
    int minimumDeviation(vector<int>& nums) {
        int minn=1e9;
        priority_queue<int> pq;
        int max=-1;
       for(int i=0;i<nums.size();++i){
           if(nums[i]%2!=0){
               nums[i]*=2;
           }
           if(nums[i]<minn){
               minn=nums[i];
           }
            if(nums[i]>max){
               max=nums[i];
           }
           pq.push(nums[i]);
       }
        int ans=max-minn;
        //cout<<max<<" "<<minn<<endl;
//         set<int> st(nums.begin(),nums.end());
//         while(*(st.rbegin())%2==0){
//            // if(max!=minn)
//             max=*(st.rbegin());
//             cout<<max<<" "<<minn<<endl;
//             st.insert(max/2);
//             st.erase(max);
          
//           //  if(max!=minn)
//             ans=min(ans,abs(max-minn));
//             minn=min(minn,max/2);
          
            
//         }
         while(pq.top()%2==0){
           // if(max!=minn)
            max=pq.top();
          //  cout<<max<<" "<<minn<<endl;
            pq.push(max/2);
            pq.pop();
          
          //  if(max!=minn)
            ans=min(ans,abs(max-minn));
            minn=min(minn,max/2);
          
            
        }
        return min(ans,pq.top()-minn);
        
    }
};