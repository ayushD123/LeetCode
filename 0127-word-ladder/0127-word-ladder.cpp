class Solution {
public:
    int ladderLength(string startWord, string targetWord, vector<string>& wordList) {
       unordered_set<string> st(wordList.begin(),wordList.end());
        queue<pair<string,int>> q;
        q.push({startWord,1});
        st.erase(startWord);
        
        while(!q.empty()){
            string word=q.front().first;
            int dis=q.front().second;
            q.pop();
            if(word==targetWord){
                return dis;
            }
            for(int i=0;i<word.size();++i){
                char org=word[i];
                for(char a='a';a<='z';++a){
                    word[i]=a;
                    if(st.find(word)!=st.end()){
                        q.push({word,dis+1});
                        st.erase(word);
                    }
                }
                word[i]=org;
            }
        }
        return 0; 
    }
};