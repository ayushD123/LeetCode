class Solution {
public:
    int strStr(string hay, string needle) {
        
        if(hay.length()<needle.length()) return -1;
         if(hay.length()==needle.length()){
             if(hay==needle) return 0;
             return -1;
         }
        
        for(int i=0,j=0;i<hay.length();i++){
            
            j=0;
            int ans=i;
            string s="";
            while(i<hay.length() && j<needle.length() && needle[j]==hay[i]){
                s.push_back(hay[i]);
                i++;
                j++;
                }
            //cout<<s<<endl;
            if(s==needle){
                return ans;
            }
            i=ans;
        }
        return -1;
    }
};