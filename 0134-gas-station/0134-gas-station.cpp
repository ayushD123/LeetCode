class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int totalgas=0,totalcost=0;
        for(auto it:gas){
            totalgas+=it;
        }
         for(auto it:cost){
            totalcost+=it;
        }
        if(totalgas<totalcost){
            return -1;
        }
        int currgas=0;
        int ans=0;
        for(int i=0;i<cost.size();++i){
            currgas+=(gas[i]-cost[i]);
            if(currgas<0){
                currgas=0;
                ans=i+1;
            }
        }
        return ans;
    }
};