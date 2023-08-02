class Solution {
public:
    vector<string> letterCombinations(string digits) {
         if(digits.size()==0) return {};
    unordered_map<char,string> mp;
    mp['2']="abc";
    mp['3']="def";
    mp['4']="ghi";
    mp['5']="jkl";
    mp['6']="mno";
    mp['7']="pqrs";
    mp['8']="tuv";
    mp['9']="wxyz";
    vector<string> output;
    output.push_back("");
    for(auto d:digits){
        vector<string> temp;
        for(auto c:mp[d]){
            for(auto it:output){
                temp.push_back(it+c);
            }
        }
        output.clear();
        output=temp;
    }
  //  sort(output.begin(),output.end());
    return output; 
    }
};