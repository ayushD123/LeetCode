class Solution {
public:
    int minimumRounds(vector<int>& tasks) {
        unordered_map<int,int> frq;
        for(auto it:tasks){
            frq[it]++;
        }
        int ans=0;
        for(auto it:frq){
            cout<<it.first<<" "<<it.second<<endl;
            if(it.second<2){
                return -1;
            }
            int x=it.second;
            if(x%3==0){
                ans+=x/3;
                
            }else if(x%3==2){
                ans=ans+1+(x/3);
            }else{
                if(x<=4){
                    ans+=x/2;
                }else{
                    if(x<=4){
                        ans+=x/2;
                    }else{
                        ans=ans+((x-4)/3)+2;
                    }
                    
                }
            }
        }
        return ans;
    }
};