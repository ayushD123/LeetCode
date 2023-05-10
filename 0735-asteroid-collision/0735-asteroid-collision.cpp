class Solution {
public:
    vector<int> asteroidCollision(vector<int>& ast) {
        stack<int> st;
        for(auto it:ast){
            if(st.empty() || it>0){
                st.push(it);
            }else{
                while(!st.empty() && st.top()>0 && abs(it)>st.top()){
                    st.pop();
                }
                if(st.empty() || st.top()<0){
                    st.push(it);
                }else{
                    if(st.top()==abs(it)){
                        st.pop();
                    }
                }
            }
        }
        vector<int> ans;
        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};