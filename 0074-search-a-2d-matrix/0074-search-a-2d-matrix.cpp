class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
       int low=0;
        int ans=matrix.size()-1;;
        int high=matrix.size()-1;
        while(low<=high){
            int mid=(low+high)/2;
            if(matrix[mid][0]==target){
                return 1;
            }
            if(matrix[mid][0]>=target){
                ans=mid-1;
                high=mid-1;
            }else{
                low=mid+1;
            }
        }
        
        if(ans<0) return 0;
        if(binary_search(matrix[ans].begin(),matrix[ans].end(),target)){
            return true;
        }else{
            return 0;
        }
    }
};