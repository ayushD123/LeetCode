class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        stack<int> st;
        int j=0;
        for(auto it:pushed){
            st.push(it);
            while(!st.empty() && st.top()==popped[j] && j<popped.size()){
                j++;
                st.pop();
            }
        }
        if(j==popped.size()){
            return true;
        }
        return false;
    }
};