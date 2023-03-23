class Solution {
public:
    
bool isAnagram(string s, string t) {
    if(s.size()!=t.size()) return 0;
    unordered_map<char,int> mp;
    for(auto it:s){
        mp[it]++;
    }
    for(auto it:t){
        mp[it]--;
       if(mp[it]<0){
           return false;
       }
    }
   // if(mp.size()==0){
        return 1;
    //}e//lse{
        //return 0;
   // }
}
};