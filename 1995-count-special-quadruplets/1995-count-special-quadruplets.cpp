class Solution {
public:
   int countQuadruplets(vector<int>& arr) {
        int c=0,n=arr.size();
         for(int i=0;i<n-3;i++){
             for(int j=i+1;j<n-2;j++){
                 for(int k=j+1;k<n-1;k++){
                     for(int l=k+1;l<n;l++){
                         if(arr[i]+arr[j]+arr[k]==arr[l])c++;
                     }
                 }
             }
         }
         return c;
    }
};