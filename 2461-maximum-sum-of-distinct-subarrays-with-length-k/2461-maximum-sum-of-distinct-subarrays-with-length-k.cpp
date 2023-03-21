class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        // unordered_set<int> st;
        unordered_map<int,int> mp;
        int i=0;
        long long sum=0;
        while(i<k){
            // st.insert(nums[i]);
            mp[nums[i]]++;
            sum+=nums[i];
            i++;
        }
        long long ans=0;
         if(mp.size()==k){
                ans=max(ans,sum);
            }
         // for(auto it:st){
         //        cout<<it<<" ";
         //    }
         //    cout<<endl;
        
        for(i=k;i<nums.size();++i){
           
            sum-=nums[i-k];
            mp[nums[i-k]]--;
            sum+=nums[i];
            mp[nums[i]]++;
            
            if(mp[nums[i-k]]==0)
            mp.erase(nums[i-k]);
          // // cout<<sum<<" "<<st.size()<<endl;
          //   for(auto it:st){
          //       cout<<it<<" ";
          //   }
          //  cout<<endl;
             if(mp.size()==k){
                ans=max(ans,sum);
            }
        }
        
        return ans;
        
    }
};