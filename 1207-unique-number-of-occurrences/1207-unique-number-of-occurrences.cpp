class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int,int> mp;
       for(int i=0;i<arr.size();++i){
           mp[arr[i]]++;
       }
        
        for(auto it:mp){
            for(auto it2:mp){
                if(it.first!=it2.first){
                    if(it.second==it2.second){
                        return false;
                    }
                }
            }
        }
        return true;
    }
};