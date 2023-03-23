class Solution {
public:
bool isAnagram(string s, string t) {
    unordered_map<char,int> mp;
    for(auto it:s){
        mp[it]++;
    }
    for(auto it:t){
        mp[it]--;
        if(mp[it]==0){
            mp.erase(it);
        }
    }
    if(mp.size()==0){
        return 1;
    }else{
        return 0;
    }
}
};