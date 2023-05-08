class Solution {
public:
    int diagonalSum(vector<vector<int>>& mat) {
        int n=mat.size();
        int sum=0;
    for(int i=0;i<mat.size();++i){
        for(int j=0;j<n;++j){
            if(i==j){
                sum+=mat[i][j];
            }
            if(i+j+1==n){
                sum+=mat[i][j];
            }
        }
    }
        
        if(n%2!=0){
            sum-=mat[n/2][n/2];
        }
        return sum;
    }
};