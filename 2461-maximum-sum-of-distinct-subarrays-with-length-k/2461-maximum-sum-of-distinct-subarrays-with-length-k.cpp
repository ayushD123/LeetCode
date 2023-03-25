class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        // unordered_set<int> st;
      //  unordered_map<int,int> mp;
        int arr[100010]={0};
        int i=0;
        long long sum=0;
        int dist=0;
        if(k==1){
            return *max_element(nums.begin(),nums.end());
        }
        while(i<k){
            // st.insert(nums[i]);
           // mp[nums[i]]++;
            arr[nums[i]]++;
            if(arr[nums[i]]==1){
                dist++;
            }
            sum+=nums[i];
            i++;
        }
        long long ans=0;
         if(dist==k){
                ans=max(ans,sum);
            }
         // for(auto it:st){
         //        cout<<it<<" ";
         //    }
         //    cout<<endl;
        cout<<dist<<endl;
        for(i=k;i<nums.size();++i){
           
            sum-=nums[i-k];
            arr[nums[i-k]]--;
             if(arr[nums[i-k]]==0)
                dist--;
            sum+=nums[i];
            arr[nums[i]]++;
            
            
             if(arr[nums[i]]==1)
                dist++;
           
           cout<<dist<<endl;
          // // cout<<sum<<" "<<st.size()<<endl;
          //   for(auto it:st){
          //       cout<<it<<" ";
          //   }
          //  cout<<endl;
             if(dist==k){
                ans=max(ans,sum);
            }
        }
        
        return ans;
        
    }
};