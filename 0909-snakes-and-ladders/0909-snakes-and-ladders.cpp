class Solution {
public:
    pair<int,int> getCords(int val,int n){
        int x=(val-1)/n;
        int y=(val-1)%n;
        int row=n-1-x;
        int col=y;
        if(x%2!=0){
            col=n-y-1;
        }
        return {row,col};
    }
    int snakesAndLadders(vector<vector<int>>& board) {
        int n=board.size();
        vector<vector<int>> vis(n,vector<int> (n,0));
        queue<pair<int,int>> q;//value at board,number of steps to go there
        q.push({1,0});
        vis[n-1][0]=1;
        while(!q.empty()){
            pair<int,int> node=q.front();
            q.pop();
            int steps=node.second;
            int val=node.first;
            cout<<val<<" "<<steps<<endl;
            // pair<int,int> cords=getCords(val,n);
            // int row=cords.first;
            // int col=cords.second;
            if(val==(n*n)){
                return steps;
            }
            for(int i=1;i<=6;++i){
                int k=val+i;
               // val+=i;
                if(k<=(n*n)){
                    pair<int,int> cords=getCords(k,n);
                    int row=cords.first;
                    int col=cords.second;
                    if(row>=n || col>=n || vis[row][col]==1) continue;
                    vis[row][col]=1;
                    if(board[row][col]==-1){
                        q.push({k,steps+1});
                    }else{
                        q.push({board[row][col],steps+1});
                    }
                }
            }
        }
        return -1;
    }
};