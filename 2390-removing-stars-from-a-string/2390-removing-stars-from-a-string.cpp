class Solution {
public:
    string removeStars(string s) {
         string st;
        for(auto it:s){
            if(it=='*'){
                st.pop_back();
            }else{
                st.push_back(it);
            }
        }
        return st;
    }
};