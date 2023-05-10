class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        
        stack<int> st;
        int n=heights.size();
     
        vector<int> l(n,-1);
        vector<int> r(n,-1);
        for(int i=n-1;i>=0;i--){
            while(!st.empty() && heights[st.top()]>=heights[i]){
                st.pop();
            }
            if(!st.empty()){
                r[i]=st.top();
            }
            st.push(i);
            
        }
        while(!st.empty()) st.pop();
        for(int i=0;i<n;i++){
            while(!st.empty() && heights[st.top()]>=heights[i]){
                st.pop();
            }
            if(!st.empty()){
                l[i]=st.top();
            }
            st.push(i);
            
        }
             int ans=0;
        for(int i=0;i<n;++i){
            
                 if(l[i]==(-1)){ //if element has no nxt greater at left
                l[i]=-1;
            }
             if(r[i]==(-1)){ //if element has no nxt greater at right
                r[i]=n;
            }
            
            int h=heights[i]*(r[i]-l[i]-1);
            ans=max(ans,h);
           // cout<<h<<" "<<i<<" "<<l[i]<<" "<<r[i]<<endl;
        }
       
       return ans;
    }
};