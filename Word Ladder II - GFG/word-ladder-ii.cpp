//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
public:
    vector<vector<string>> findSequences(string beginWord, string endWord, vector<string>& wordList) {
        // code here
        unordered_set<string> wordset(wordList.begin(), wordList.end());
        //* Creating an unordered_setset of string type to store every word.

        vector<string> usedWords;
        //* words that are used will be used in usedWords.

        vector<vector<string>> ans;
        //* Storing all the possible sequences that can be formed.

        queue<vector<string>> q;
        //* Queue of vector<string> type to store the sequences.

        q.push({beginWord});
        usedWords.push_back(beginWord);
        //* beginWord is pushed into the queue , henced adding it to the usedWords vector

        bool flag = false;
        //* A small check to break the while loop (when the endword is found at any level in a vector)

        while (!q.empty())
        {
            int size = q.size();

            for (string delwords : usedWords)
            {
                wordset.erase(delwords);
                //? Deleting all the previously used words from the wordset.
                //* Ensures that the same word isn't used again.
            }

            usedWords.clear();

            //? This for loop ensures that all vectors of same size or at same level are checked in one go.
            //* Else wordset will no longer have the words that can be used in another vector.
            //* eg : in vector {abp , adp , kdp, kdz} we already used "KDP" but another vector v2 {abp , kbp, kdp, kdz};
            //* Can be formed with same endWord and same length but we wont be able to used KDP again if we dont use the for loop for each levels.
            for (int i = 0; i < size; i++)
            {
                //*Storing the current vector.
                vector<string> qwordlist = q.front();
                q.pop();

                //? Checks for the endWord which should be present at the last index in the vector
                if (qwordlist.back() == endWord)
                {
                    //* If present , add the vector that has the correct sequence
                    ans.push_back(qwordlist);

                    flag = true;

                    //* Skip the addition of any word since we already found our endWord.
                    continue;
                }

                //* Last word -> transform it to another word , stored in the queue
                string lastword = qwordlist.back();

                int strsize = lastword.size(); // can define outside queue as well , since all word size = beginWord.size().

                //? For loop runs for the number of characters.
                for (int idx = 0; idx < strsize; idx++)
                {
                    char original_char = lastword[idx];

                    for (char ch = 'a'; ch <= 'z'; ch++)
                    {
                        lastword[idx] = ch;

                        if (wordset.find(lastword) != wordset.end())
                        {
                            //*If the modified word is found , push it (into the vector then into the queue ) as well as (in the usedWord vector).
                            qwordlist.push_back(lastword);
                            q.push(qwordlist);
                            usedWords.push_back(lastword);

                            //?Removal of the added lastword , since in the next iteration we do not want to add a new word to updated qwordList.
                            qwordlist.pop_back();
                        }
                    }

                    lastword[idx] = original_char;
                }
            }

            if (flag)
                break;
        }

        return ans;
    }
};

//{ Driver Code Starts.

bool comp(vector<string> a, vector<string> b)
{
    string x = "", y = "";
    for(string i: a)
        x += i;
    for(string i: b)
        y += i;
    
    return x<y;
}

int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<string>wordList(n);
		for(int i = 0; i < n; i++)cin >> wordList[i];
		string startWord, targetWord;
		cin >> startWord >> targetWord;
		Solution obj;
		vector<vector<string>> ans = obj.findSequences(startWord, targetWord, wordList);
		if(ans.size()==0)
		    cout<<-1<<endl;
		else
		{
		    sort(ans.begin(), ans.end(), comp);
            for(int i=0; i<ans.size(); i++)
            {
                for(int j=0; j<ans[i].size(); j++)
                {
                    cout<<ans[i][j]<<" ";
                }
                cout<<endl;
            }
		}
	}
	return 0;
}
// } Driver Code Ends