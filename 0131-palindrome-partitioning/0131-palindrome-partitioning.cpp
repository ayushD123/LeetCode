class Solution {
public:
    
    void solve(int ind,string s,vector<vector<string>> &ans,vector<string> &subst){
            if(ind==s.size()){
                ans.push_back(subst);
                return;
            }
            
            for(int i=ind;i<s.size();++i){
                if(isPalindrome(s,ind,i)){
                    subst.push_back(s.substr(ind,i-ind+1));
                    solve(i+1,s,ans,subst);
                    subst.pop_back();
                }
            }
        }
    
    bool isPalindrome(string s,int i,int j){
        while(i<=j){
            if(s[i++]!=s[j--]) return false;
            
        }
             return true;
             
    }
        
    
    vector<vector<string>> partition(string s) {
        
        vector<string> subst;
         vector<vector<string>>ans;
            solve(0,s,ans,subst);
        return ans;
    }
};