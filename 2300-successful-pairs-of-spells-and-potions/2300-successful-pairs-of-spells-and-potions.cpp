class Solution {
public:
    int valid_pos(vector<int>& potions, long long success, int spell){
        long potion_needed = (success + spell - 1) / spell;

        int l=0,r=potions.size();
        while(l<r){
            int mid = l + (r-l)/2;
            if(potions[mid] >= potion_needed)
                r = mid;
            else
                l = mid + 1;
        }
        return l;
    }
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        sort(potions.begin(),potions.end());
        vector<int> v;
        for(auto x:spells){
            long key = (success + x - 1) / x;
            int ans=valid_pos(potions,success,x);
            v.push_back(potions.size()-ans);
        }
        return v;
    }
};