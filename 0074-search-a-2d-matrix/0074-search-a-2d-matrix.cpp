class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n=matrix.size();
        int m=matrix[0].size();
        for(auto it:matrix){
            for(auto bt:it){
                if(bt==target){
                    return true;
                }
            }
        }
        return false;
    }
};