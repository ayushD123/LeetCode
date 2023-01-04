class Solution {
public:
    bool equalFrequency(string word) {
//         unordered_map<char, int> mp1;
//         unordered_map<int, int> mp2;
//         for(auto it: word){
//             mp1[it]++;
           
//         }  
//          for(auto it: mp1){
//             mp2[it.second]++;
           
//         }
//         if(mp2.size()>2) return false;
        
        
        
        vector<int> freq(26);
        
        for(auto it : word) {
            freq[it - 'a'] += 1;
        }
        
        int mx_freq = 0;
        int mn_freq = word.size();
        int cnt_mx = 0;
        int cnt_mn = 0;
        
        for(int i = 0; i < 26; ++i) {
            mx_freq = max(mx_freq, freq[i]);                 
            if(freq[i] > 0) mn_freq = min(mn_freq, freq[i]); 
        }
        for(auto it:freq){
            cout<<it<<" ";
        }
        
        for(int i = 0; i < 26; ++i) {
            if(freq[i] == mx_freq)
                ++cnt_mx;        
            else if(freq[i] == mn_freq)
                ++cnt_mn;      
             else if(freq[i] > 0) 
                 return false;  
        }
        
        if(mx_freq == mn_freq)
            return cnt_mx == 1 || mx_freq == 1;
        
        if(cnt_mn == 1 && mn_freq == 1)
            return true;
        
        if(mx_freq != mn_freq + 1 || cnt_mx != 1)
            return false;
        
        return true;
    }
};