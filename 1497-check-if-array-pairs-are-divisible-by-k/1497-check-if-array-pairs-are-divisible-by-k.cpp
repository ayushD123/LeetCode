class Solution {
public:
    typedef long long ll;
    bool canArrange(vector<int>& arr, int k) {
        unordered_map<int, int> map;
        int n =arr.size( );
for( int i =0;i<n;i++){
    int currentvalue= arr[i];
int current_remainder = ((currentvalue%k )+ k) % k;
map[ current_remainder]++;
}

for(auto it=map.begin( ); it!=map.end ( ); it++){
if(it->first==0){
if(map[it->first]%2!=0)
return false;
}
else if(map. find( k-it->first) ==map.end())
return false;
else if (map [ it->first] !=map [k-it->first] )
return false;
        }
return true;
    }
};