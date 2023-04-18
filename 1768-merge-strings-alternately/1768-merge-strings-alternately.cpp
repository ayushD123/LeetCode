class Solution {
public:
    string mergeAlternately(string word1, string word2) {
      
	  int a=word1.length();
        int b=word2.length();
        string ans;
        string app;
        if(a>b){
            for(int i=b;i<a;++i){
                app.push_back(word1[i]);
            }
            int n=a-b;
            while(n--){
                word1.pop_back();
            }
        }else
            {
                for(int i=a;i<b;++i){
                app.push_back(word2[i]);
            }
            int n=b-a;
            while(n--){
                word2.pop_back();
            }
            
        }

          a=word1.length();
        b=word2.length();
            for(int i=0;i<a;++i){
                ans.push_back(word1[i]);
                ans.push_back(word2[i]);
            
        }
        cout<<app<<endl;
        ans+=app;
        return ans;
    }
};