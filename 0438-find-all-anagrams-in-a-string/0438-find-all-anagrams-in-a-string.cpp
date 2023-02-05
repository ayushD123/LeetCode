class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> ans;
        
       //  sort(s1.begin(),s1.end());
        if(p.size()>s.size()) return ans;
        // if(s1.size()==s2.size()){
        //     string a=s2;
        //     sort(a.begin(),a.end());
        //     if(a!=s1)
        //     return ans;
        // }
        int k=p.size();
        map<char,int> mp1;
        for(auto it:p){
            mp1[it]++;
        }
        string a=s.substr(0,k);
        map<char,int> mp2;
        for(auto it:a){
            mp2[it]++;
        }
       //   for(auto it:mp1){
       //     //     cout<<it.first<<" "<<it.second<<endl;
       //      }
       // // cout<<"mp2"<<endl;
        
        for(int i=0;i<s.size()-k+1;++i){
            // cout<<i<<endl;
            // for(auto it:mp2){
            //    cout<<it.first<<" "<<it.second<<endl;
            // }
            if(mp1==mp2){
                ans.push_back(i);
            }
            char a=s[i];
            char b=s[k+i];
            mp2[a]--;
            if(mp2[a]==0){
                mp2.erase(a);
            }
            mp2[b]++;
            
        }
        return ans;
    }
};