//{ Driver Code Starts
// Initial template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template in C++

class Solution 
{
    public:
    //Function to find minimum number of pages.
    int findPages(int A[], int N, int M) 
    {
        //code here
        if(M>N) return -1;
        int low=1;
        int high=accumulate(A, A+N,(long) 0);
        int ans=-1;
        while(low<=high){
            int mid=(low+high)/2;
            int sum=0;
            int k=1;
            for(int i=0;i<N;++i){
                if(A[i]>mid){
                    k=1e9;
                    break;
                }
                sum+=A[i];
                if(sum>mid){
                    sum=A[i];
                    k++;
                }
            }
           // cout<<mid<<" ";
            if(k<=M){
                ans=mid;
                high=mid-1;
            }else{
                low=mid+1;
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int A[n];
        for(int i=0;i<n;i++){
            cin>>A[i];
        }
        int m;
        cin>>m;
        Solution ob;
        cout << ob.findPages(A, n, m) << endl;
    }
    return 0;
}

// } Driver Code Ends