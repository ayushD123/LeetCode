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
        vector<int> mp1(26,0);
     //   map<char,int> mp1;
        for(auto it:p){
            mp1[it-'a']++;
        }
        string a=s.substr(0,k);
       // map<char,int> mp2;
        vector<int> mp2(26,0);
        for(auto it:a){
            mp2[it-'a']++;
        }
       //   for(auto it:mp1){
       //     //     cout<<it.first<<" "<<it.second<<endl;
       //      }
       // // cout<<"mp2"<<endl;
        if(mp1==mp2){
            ans.push_back(0);
        }
        int j=k;
        for(int i=0;i<s.size()-k+1 && j<s.size();++i,j++){
            // cout<<i<<endl;
            // for(auto it:mp2){
            //    cout<<it.first<<" "<<it.second<<endl;
            // }
           
            char a=s[i];
            char b=s[j];
          mp2[a-'a']--;
          //  cout<<b<<" "<<b-'a';
            // if(mp2[a]==0){
            //     mp2.erase(a);
            // }
         //   cout<<i<<" "<<j<<endl;
           mp2[b-'a']++;
             if(mp1==mp2){
                ans.push_back(i+1);
            }
            
        }
        return ans;
    }
};