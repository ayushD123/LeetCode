class Solution {
public:
    
//     bool isSafe(int row,int col,vector<string> b,int n){
//         int tempr=row;
//         int tempc=col;
//         while(row>=0 && col>=0){
//             if(b[row][col]=='Q')
//                 return false;
            
//             row--;
//             col--;
//         }
//         row=tempr;
//         col=tempc;
//           while(col>=0){
//             if(b[row][col]=='Q')
//                 return false;
            
//             //row--;
//             col--;
//         }
//          row=tempr;
//         col=tempc;
//          while(row<n && col>=0){
//             if(b[row][col]=='Q')
//                 return false;
            
//             row++;
//             col--;
//         }
//         return true;
        
        
//     }
    
    void recur(int col,vector<vector<string>> &ans,vector<string> &b,int n,vector<int> &roww,vector<int> &uppdiag,vector<int> &lowdiag){
        if(col==n){
            ans.push_back(b);
            return;
        }
        for(int row=0;row<n;++row){
        //    if(isSafe(row,col,b,n)){
            if(roww[row]) continue;
               if(uppdiag[row+col]) continue;
               if(lowdiag[n-1+col-row]) continue;
                
            
            roww[row] = 1;
         uppdiag[row + col] = 1;
         lowdiag[n - 1 + col - row] = 1;
                b[row][col]='Q';
                recur(col+1,ans,b,n,roww,uppdiag,lowdiag);
                b[row][col]='.';
            roww[row] = 0;
         uppdiag[row + col] = 0;
          lowdiag[n - 1 + col - row] = 0;
          }
        }
    
    public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<string> v(n);
        vector<int> roww(n,0);
        vector<int> uppdiag(2*n-1,0);
        vector<int> lowdiag(2*n-1,0);
        string s(n,'.');
        for(int i=0;i<n;++i){
            v[i]=s;
        }
        recur(0,ans,v,n,roww,uppdiag,lowdiag);
        return ans;
        
    }
};