//{ Driver Code Starts
//Initial Template for C++
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++
class Solution{
    private:
    int dfs(int index, vector<int> &vis, vector<int> &path,int n, vector<int> &arr){
        if(index>=n || index<0){
            return 1;
        }
        if(vis[index]==2) return 2; //next to a node wich is part of a cycle
        if(path[index]) return 2; //same path 
        
        vis[index]=1;
        path[index]=1;
        int newind=index+arr[index];
        if(dfs(newind,vis,path,n,arr)==2)
            vis[index]=2;
        path[index]=0;
        return vis[index];
    }
public:
    int goodStones(int n,vector<int> &arr){
        // Code here
        vector<int> vis(n,0);//3 values[0--not visted yet,1-->visited but not part of cycle,2-->part of cycle(obvoiusly visited)]
        vector<int> path(n,0);
        
        for(int i=0;i<n;++i){
            if(!vis[i]){
                vis[i]=dfs(i,vis,path,n,arr);
            }
            
        }
        int cnt=0;
        for(auto it:vis){
            if(it==1){
                cnt++;
            }
        }
        return cnt;
    }  
};

//{ Driver Code Starts.

int main(){
    
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> arr(n);
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        Solution ob;
        cout<<ob.goodStones(n,arr)<<endl;
    }
    return 0;
}
// } Driver Code Ends