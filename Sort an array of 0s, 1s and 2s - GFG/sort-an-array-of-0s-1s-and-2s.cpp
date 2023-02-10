//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;



// } Driver Code Ends
class Solution
{
    public:
    void sort012(int a[], int n)
    {
        // code here 
    //     int lo=0;
    //     int mid=0;
    //     int high=n-1;
    //     while(mid<=high){
    //         if(a[mid]==0){
    //             swap(a[mid],a[lo]);
    //             mid++;
    //             lo++;
    //         }else{
    //              if(a[mid]==2){
    //             swap(a[mid],a[high]);
    //             //mid++;
    //             high--;
    //         }else{
    //             mid++;
    //         }
    //     }
    // }
    
    int cnt0=0;
    int cnt1=0;
    int cnt2=0;
    for(int i=0;i<n;++i){
        if(a[i]==0){
            cnt0++;
        }else if(a[i]==1){
            cnt1++;
        }else{
            cnt2++;
        }
    }
    int i=0;
    while(cnt0>0){
        a[i++]=0;
        cnt0--;
    }
     while(cnt1>0){
        (a[i++]=1);
        cnt1--;
    }
     while(cnt2>0){
        (a[i++]=2);
        cnt2--;
    }
    }
    
};

//{ Driver Code Starts.
int main() {

    int t;
    cin >> t;

    while(t--){
        int n;
        cin >>n;
        int a[n];
        for(int i=0;i<n;i++){
            cin >> a[i];
        }

        Solution ob;
        ob.sort012(a, n);

        for(int i=0;i<n;i++){
            cout << a[i]  << " ";
        }

        cout << endl;
        
        
    }
    return 0;
}


// } Driver Code Ends