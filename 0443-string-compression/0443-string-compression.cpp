class Solution {
public:
    int compress(vector<char>& chars) {
        // unordered_map<char,int> mp;
        // for(auto it:chars){
        //     mp[it]++;
        // }
        if(chars.size()<2){
            return chars.size();
        }
       int i=0;
        int j=1;
        for(i=0,j=0;j<chars.size();){
            int cnt=0;
           // cout<<i<<" "<<j<<endl;
            while(j<chars.size() && chars[i]==chars[j]){
                cnt++;
                j++;
            }
            
            //cout<<cnt<<" ";
            string c=to_string(cnt);
            char cn=c[0];
           // cout<<c<<" ";
              if(cnt>1){
                chars.erase(chars.begin()+i,chars.begin()+j-1);
            }
             string s=to_string(cnt);
            if(cnt>1){
               
                
                for(int k=0;k<s.length();++k){
                    chars.insert(chars.begin()+i+1+k,s[k]);
                }
            }
           cout<<cnt<<" ";
           // cout<<s<<endl;
            if(cnt>1)
          j=i+s.length()+1;
           
            i=j;
        }
        return chars.size();
        
    }
};