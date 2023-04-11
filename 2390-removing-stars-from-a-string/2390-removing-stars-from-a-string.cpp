class Solution {
public:
    string removeStars(string s) {
        stack<char> st;
        for(auto it:s){
            if(it=='*'){
                st.pop();
            }else{
                st.push(it);
            }
        }
        s="";
        while(!st.empty()){
            s+=st.top();
            st.pop();
        }
        reverse(s.begin(),s.end());
        return s;
    }
};