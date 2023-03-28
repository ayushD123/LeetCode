class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& arr, int k) {
       sort(arr.begin(),arr.end());
        int n=arr.size();
        vector<vector<int>> ans;
        set<vector<int>> st;
        for(int i=0;i<n-3;++i){
           long long x=k-arr[i];
          for(int j=i+1;j<n-2;++j){
              long long y=x-arr[j];
              int left=j+1;
              int right=n-1;
              while(left<right){
                   long long sum=arr[left]+arr[right];
                  if(sum==y){
                      vector<int> t= {arr[i],arr[j],arr[left],arr[right]};
                     // ans.push_back(t);
                      st.insert(t);
                      left++;
                      right--;
                  }else{
                      if(sum<y){
                          left++;
                      }else{
                          right--;
                      }
                  }
              }
          }
        }
        for(auto it:st){
            ans.push_back(it);
        }
        return ans;
    }
};