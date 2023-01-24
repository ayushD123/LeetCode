class Solution {
public:
    pair<int,int> getCords(int curr,int n){
       int r = n - (curr - 1) / n  -1;
        int c = (curr - 1) % n;
        if (r % 2 == n % 2) {
            return {r, n - 1 - c};
        } else {
            return {r, c};
        }
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