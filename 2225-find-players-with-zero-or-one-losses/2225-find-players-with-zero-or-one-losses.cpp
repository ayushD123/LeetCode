class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        unordered_map<int,int> win;
        unordered_map<int,int> lost;
        vector<int> list;
        set<int> st;
        int n=matches.size();
        for(int i=0;i<n;++i){
          // win[matches[i][0]]++;
           lost[matches[i][1]]++;
            // list.push_back(matches[i][0]);
            // list.push_back(matches[i][1]);
            st.insert(matches[i][0]);
            st.insert(matches[i][1]);
        }
        int k=0;
        for(auto it:st){
            list.push_back(it);
        }
        sort(list.begin(),list.end());
        vector<int> l1;
        vector<int> l2;
        
         for(auto it:list){
            cout<<it<<" ";
        }
        
        
        for(int i=0;i<list.size();++i){
            if(lost.find(list[i])==lost.end()){
                l1.push_back(list[i]);
                
            }
             if(lost[list[i]]==1){
                l2.push_back(list[i]);
                
            }
            
        }
        vector<vector<int>> ans;
        ans.push_back(l1);
                ans.push_back(l2);
        return ans;
    }
};