//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
bool issafe(int i,int j, vector<vector<int>> mat){
    int n=mat.size();
    int a=i;
    int b=j;
    while(i>=0){
        if(mat[i][j]==1) return 0;
        i--;
    }
    i=a;
      while(i>=0 && j>=0){
        if(mat[i][j]==1) return 0;
        i--;
        j--;
    }
    i=a;
    j=b;
      while(i>=0 && j<n){
        if(mat[i][j]==1) return 0;
        i--;
        j++;
    }
    return 1;


}

void nqueen(int n,int i,  vector<vector<int>> mat,vector<vector<int>> &ans){
    if(i>=n){
        vector<int> tmp;
       for(int i=0;i<n;++i){
           for(int j=0;j<n;++j){
               if(mat[j][i]==1){
                   tmp.push_back(j+1);
               }
           }
       }
       ans.push_back(tmp);
        return;
    }
    for(int j=0;j<n;++j){
        if(issafe(i,j,mat)){
            mat[i][j]=1;
            nqueen(n,i+1,mat,ans);

        }
        mat[i][j]=0;
    }
    return;
}
    vector<vector<int>> nQueen(int n) {
        // code here
        vector<vector<int>> mat;
       vector<vector<int>> ans; 
          for(int i=0;i<n;++i){
        vector<int> v(n,0);
        mat.push_back(v);
    }
    
    nqueen(n,0,mat,ans);
    sort(ans.begin(),ans.end());
    return ans;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        
        Solution ob;
        vector<vector<int>> ans = ob.nQueen(n);
        if(ans.size() == 0)
            cout<<-1<<"\n";
        else {
            for(int i = 0;i < ans.size();i++){
                cout<<"[";
                for(int u: ans[i])
                    cout<<u<<" ";
                cout<<"] ";
            }
            cout<<endl;
        }
    }
    return 0;
}
// } Driver Code Ends