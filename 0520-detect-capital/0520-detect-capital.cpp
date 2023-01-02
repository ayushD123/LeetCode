class Solution {
public:
    bool lflag=0;
    
    bool detectCapitalUse(string word) {
        int ucount=0;
        int lcount=0;
        if(isupper(word[0])) lflag=1;
        for(int i=0;i<word.length();++i){
           if(isupper(word[i])) ucount+=1;
            if(islower(word[i])) lcount+=1;
            
        }
        if(ucount==word.size()){
            return true;
        }
         if(lcount==word.size()){
            return true;
        }
         if(lflag && lcount==word.size()-1){
            return true;
        }
        return false;
    }
};