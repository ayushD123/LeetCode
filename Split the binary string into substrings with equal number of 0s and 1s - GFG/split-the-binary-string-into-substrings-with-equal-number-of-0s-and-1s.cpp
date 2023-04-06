//{ Driver Code Starts
/* Driver program to test above function */

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
    int maxSubStr(string str){
        //Write your code here
      
        int o=0;
        int z=0;
        int x=0;
        int y=0;
        int cnt=0;
        for(auto it:str){
            if(it=='1'){
                x++;
                o++;
            }else{
                y++;
                z++;
            }
            if(x==y){
                cnt++;
                x=0;
                y=0;
            }
        }
        if(o!=z) return -1;
        if(cnt==0) return -1;
        return cnt;
    }
};


//{ Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
	    string str;
	    cin >> str;
	    Solution ob;
	    int ans = ob.maxSubStr(str);
	    cout << ans<<endl;
	}
	return 0;
}

// } Driver Code Ends