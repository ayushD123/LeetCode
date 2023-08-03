class Solution {
public:
    void solve(vector<string> &ans,string tmp,int n,int open,int close){
        if(tmp.length()>=(2*n)){
            ans.push_back(tmp);
            return;
        }
        if(open<n){
            tmp.push_back('(');
            open++;
            solve(ans,tmp,n,open,close);
            tmp.pop_back();
            open--;
        }
        if(close<open){
            tmp.push_back(')');
            close++;
             solve(ans,tmp,n,open,close);
            tmp.pop_back();
            close--;
        }
        
    }
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        solve(ans,"",n,0,0);
        return ans;
    }
};