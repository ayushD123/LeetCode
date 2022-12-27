class Solution {
public:
   int maximumBags(vector<int>& capacity, vector<int>& rocks, int additionalRocks) {
        // long long totalcap=0;
        // for(auto it:capacity){
        //     totalcap+=it;
        // }
        // long long totalrocks=0;
        //  for(auto it:rocks){
        //     totalrocks+=it;
        // }
        // if(totalrocks+additionalRocks>=totalcap){
        //     return rocks.size();
        // }
        int cnt=0;
        int n=rocks.size();
        vector<int> rem;
        for(int i=0;i<rocks.size();++i){
            rem.push_back(capacity[i]-rocks[i]);
        }

        sort(rem.begin(),rem.end());
        // for(auto it:rem){
        //     cout<<it<<" ";
        // }
      //  cout<<endl;
        int sum=0;
        int i=0;
        while(sum<=additionalRocks && i<n){
            sum+=rem[i];
            if(sum<=additionalRocks){
               rem[i]=0;
            i++; 
            }
            
        }
       //  int i=0;
       // int k= additionalRocks;
       //  while(k>0){
       //      if(rem[i%n]>0){
       //          rem[i%n]--;
       //          k--;
                
       //      }
       //      i++;
       //  }
        // for(auto it:rem){
        //     cout<<it<<" ";
        // }
        // cout<<endl;
       // sort(rem.begin(),rem.end());
        for(auto it:rem){
            if(it<=0){
                cnt++;
            }
        }
        return cnt;
        
    }
};