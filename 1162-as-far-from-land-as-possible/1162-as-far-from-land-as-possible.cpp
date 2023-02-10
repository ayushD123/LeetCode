class Solution {
public:
    int maxDistance(vector<vector<int>>& grid) {
        queue<vector<int>> q;
        int n=grid.size();
        int m=grid[0].size();
        bool haswater=0;
        bool hasland=0;
        for(int i=0;i<n;++i){
            for(int j=0;j<m;++j){
                if(grid[i][j]==0){
                    haswater=1;
                }
                if(grid[i][j]==1){
                    hasland=true;
                    q.push({i,j,0});
                }
            }
        }
        if((haswater & hasland)==false){
            return -1;
        }
        int max=-1;
           vector<vector<int>> vis(n,vector<int> (m,0));
        while(!q.empty()){
            vector<int> v=q.front();
            int row=v[0];
            int col=v[1];
            int dist=v[2];
            if(dist>max){
                max=dist;
            }
            q.pop();
            for(int del_row=-1;del_row<=1;del_row++){
                for(int del_col=-1;del_col<=1;del_col++){
                     if((del_row==-1&&del_col==-1) || (del_row==-1&&del_col==1) || (del_row==1&&del_col==-1) || (del_row==1&&del_col==1)){
                        continue;
                    }
                    int nrow=row+del_row;
                    int ncol=col+del_col;
                    if(nrow<0 || ncol<0 || nrow>=n || ncol>=n){
                        continue;
                    }
                    if(vis[nrow][ncol]==0 && grid[nrow][ncol]==0){
                        cout<<nrow<<" "<<row<<endl;
                        cout<<ncol<<" "<<col<<endl;
                      //  int ndist=abs(nrow-row)+abs(ncol-col);
                        vis[nrow][ncol]=1;
                        q.push({nrow,ncol,dist+1});
                    }
        }
            }
        }
            return max;
        
    }
};