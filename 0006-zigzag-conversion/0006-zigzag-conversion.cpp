class Solution {
public:
    string convert(string s, int numRows) {
        int n=int(s.size());
        if(numRows==1 || s.length()<=1){
            return s;
        }
        int sec=ceil(n/(2*numRows-2.0));
        int cols=sec*(numRows-1);
        vector<vector<char>> mat(numRows,vector<char>(cols,' '));
        int currRow=0;
        int currCol=0;
        int currInd=0;
        while(currInd<n){
            while(currRow<numRows && currInd<n){
                mat[currRow][currCol]=s[currInd];
                currRow++;
                currInd++;
            }
            currRow-=2;
            currCol+=1;
            
            while(currCol<cols && currRow>0 && currInd<n){
                mat[currRow][currCol]=s[currInd];
                currRow--;
                currCol++;
                currInd++;
            }
            
        }
        string ans="";
        for(auto& row:mat){
            for(auto& ch:row){
                if(ch!=' '){
                    ans+=ch;
                }
            }
        }
        return ans;
    }
};