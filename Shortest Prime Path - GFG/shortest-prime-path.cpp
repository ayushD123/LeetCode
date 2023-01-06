//{ Driver Code Starts
//Initial Template for C++
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++
class Solution{   
  public:
    int shortestPath(int Num1,int Num2)
    {   
        // Complete this function using prime vector
        vector<int> isprime(10000,1);
        isprime[0]=0;
        isprime[1]=0;
        for(int i=2;i<10000;i++){
           if(isprime[i]==1)
            for(int j=i*2;j<10000;j=j+i){
                isprime[j]=0;
            }
        }
        vector<int> vis(10000,0);
        queue<pair<int,int>> q;
        q.push({Num1,0});
        vis[Num1];
        while(!q.empty()){
            int num=q.front().first;
            int dis=q.front().second;
            q.pop();
            if(num==Num2){
                return dis;
                
            }
            string s=to_string(num);
            for(int i=0;i<4;++i){
                char org=s[i];
                for(int j=0;j<=9;++j){
                    if(i==0 && j==0) continue;
                    s[i]=j+'0';
                    int x=stoi(s);
                   
                    if(vis[x]==0 && isprime[x]){
                       
                     // cout<<x<<endl;
                        vis[x]=1;
                        q.push({x,dis+1});
                    }
                }
                s[i]=org;
            }
        }
        return 50;
    }
};


//{ Driver Code Starts.
signed main()
{
    int t;
    cin>>t;
    Solution obj;
    while(t--)
    {
        int Num1,Num2;
        cin>>Num1>>Num2;
        int answer=obj.shortestPath(Num1,Num2);
        cout<<answer<<endl;
    }
}
// } Driver Code Ends