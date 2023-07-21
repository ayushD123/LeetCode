class Solution {
public:
    vector<int> decode(vector<int>& encoded, int first) {
        int n=encoded.size();
        vector<int> arr(n+1,0);
        arr[0]=first;
        arr[1]=first^encoded[0];
        for(int i=1;i<n;++i){
            arr[i+1]=encoded[i]^arr[i];
        }
        return arr;
    }
};