class Solution {
public:
    bool closeStrings(string word1, string word2) {
        
       if(word1.size()!=word2.size()) return false;
        
        vector<int> v1(26,0);//number of occurence of word1
        vector<int> v2(26,0);//number of occurence of word2
        vector<int> v3(26,0);//char present in word1
        vector<int> v4(26,0);//char present in word2
        
        
        for(int i=0;i<word1.size();++i){
            v1[word1[i]-'a']++;
            v2[word2[i]-'a']++;
            v3[word1[i]-'a']=1;//to mark to each char present in word into alphabet set
            v4[word2[i]-'a']=1;
        }
        sort(v1.begin(),v1.end());
        sort(v2.begin(),v2.end());
        if(v1==v2 && v3==v4) return true;
        return false;
    
    }
};