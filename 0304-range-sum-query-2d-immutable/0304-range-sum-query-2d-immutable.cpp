class NumMatrix {
public:
    vector<vector<int>> prefixsum;
    NumMatrix(vector<vector<int>>& matrix) {
        int m=matrix.size();
        int n=matrix[0].size();
        prefixsum.resize(m+1);
        for(int i=0;i<=m;++i){
            prefixsum[i].resize(n+1,0);
            for(int j=0;j<=n;++j){
                if(i==0 || j==0) continue;
                prefixsum[i][j]=prefixsum[i-1][j]+prefixsum[i][j-1]+matrix[i-1][j-1]-prefixsum[i-1][j-1];
                
            }
        }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        int r1=row1+1;
        int r2=row2+1;
        int c1=col1+1;
        int c2=col2+1;
        // int brow=max(r1,r2);
        // int fcol=min(c1,c2);
        // int frow=min(r1,r2);
        // int rcol=max(c1,c2);
        int ans=prefixsum[r2][c2]+prefixsum[r1-1][c1-1]-prefixsum[r2][c1-1]-prefixsum[r1-1][c2];
        return ans;
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */