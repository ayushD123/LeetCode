//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    pair<long,long> indexes(vector<long long> v, long long x)
    {
        // code here
        pair<long,long> ans={-1,-1};
        int i=0;
        int j=v.size()-1;
        while(i<=j){
            int mid=(i+j)/2;
            if(v[mid]==x){
                j=mid-1;
                ans.first=mid;
            }else{
                if(v[mid]<x){
                    i=mid+1;
                }else{
                    j=mid-1;
                }
            }
        }
        i=0;
        j=v.size()-1;
          while(i<=j){
            int mid=(i+j)/2;
            if(v[mid]==x){
                i=mid+1;
                ans.second=mid;
            }else{
                if(v[mid]<x){
                    i=mid+1;
                }else{
                    j=mid-1;
                }
            }
        }
        
        return ans;
    }
};

//{ Driver Code Starts.

int main()
 {
    long long t;
    cin>>t;
    while(t--)
    {
        long long n, k;
        vector<long long>v;
        cin>>n;
        for(long long i=0;i<n;i++)
        {
            cin>>k;
            v.push_back(k);
        }
        long long x;
        cin>>x;
        Solution obj;
        pair<long,long> pair = obj.indexes(v, x);
        
        if(pair.first==pair.second and pair.first==-1)
        cout<< -1 <<endl;
        else
        cout<<pair.first<<" "<<pair.second<<endl;

    }
	return 0;
}

// } Driver Code Ends