//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
    private:
    bool dfs(int row,int col,vector<vector<char>>& board, string word, vector<vector<int>> &vis,int 
             
             cnt){
        int n=board.size();
        int m=board[0].size();
        if(cnt==word.length()) return true;;
        if(row<0 || col<0 || row>=n || col>=m) return false;;
        if(vis[row][col]) return false;
        if(board[row][col]!=word[cnt]) return false;
        cnt+=1;
        vis[row][col]=1;
        bool ans=(dfs(row+1,col,board,word,vis,cnt) || 
        dfs(row-1,col,board,word,vis,cnt) || 
        dfs(row,col+1,board,word,vis,cnt) || 
        dfs(row,col-1,board,word,vis,cnt) ||
        dfs(row-1,col-1,board,word,vis,cnt) ||
        dfs(row+1,col-1,board,word,vis,cnt) ||
        dfs(row-1,col+1,board,word,vis,cnt) ||
        dfs(row+1,col+1,board,word,vis,cnt));
        vis[row][col]=0;
        
        
        return ans;
    }
public:
	vector<string> wordBoggle(vector<vector<char> >& board, vector<string>& dictionary) {
	  int n=board.size();
        int m=board[0].size();
        vector<vector<int>> vis(n,vector<int>(m,0));
        int nd=dictionary.size();
        vector<string> ans;
        
        int cnt=0;
        for(auto word:dictionary){
            int x=0;
            for(int i=0;i<n;++i){
            for(int j=0;j<m;++j){
                
                if(board[i][j]==word[0]){
                //    vector<vector<int>> temp=vis;
                    if(dfs(i,j,board,word,vis,cnt)){
                    ans.push_back(word);
                    x=1;
                    break;
                }
               // if(x) break;
            }
            if(x) break;
        }
        if(x) break;
        }
        
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        vector<string> dictionary;
        for (int i = 0; i < N; ++i) {
            string s;
            cin >> s;
            dictionary.push_back(s);
        }
        
        int R, C;
        cin >> R >> C;
        vector<vector<char> > board(R);
        for (int i = 0; i < R; i++) {
            board[i].resize(C);
            for (int j = 0; j < C; j++) cin >> board[i][j];
        }
        Solution obj;
        vector<string> output = obj.wordBoggle(board, dictionary);
        if (output.size() == 0)
            cout << "-1";
        else {
            sort(output.begin(), output.end());
            for (int i = 0; i < output.size(); i++) cout << output[i] << " ";
        }
        cout << endl;
    }
}

// } Driver Code Ends