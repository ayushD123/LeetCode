class Solution {
public:
     int largestRectangleArea(vector<int>& heights) {
        
        stack<int> st;
        int n=heights.size();
     
        vector<int> l(n,-1);
        vector<int> r(n,n);
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
            
            //      if(l[i]==(-1)){ //if element has no nxt greater at left
            //     l[i]=-1;
            // }
            //  if(r[i]==(-1)){ //if element has no nxt greater at right
            //     r[i]=n;
            // }
            
            int h=heights[i]*(r[i]-l[i]-1);
            ans=max(ans,h);
           // cout<<h<<" "<<i<<" "<<l[i]<<" "<<r[i]<<endl;
        }
       
       return ans;
     }
    int maximalRectangle(vector<vector<char>>& matrix) {
        int n=matrix.size();
        int m=matrix[0].size();
        vector<int> curr(m,0);
        for(int i=0;i<m;++i){
            if(matrix[0][i]=='1'){
                curr[i]=1;
            }
        }
        //  for(auto it:curr){
        //         cout<<it<<" ";
        //     }
        // cout<<endl;
      //  cout<<n<<" "<<m<<endl;
        int ans=largestRectangleArea(curr);
        for(int i=1;i<n;++i){
            for(int j=0;j<m;++j){
                if(matrix[i][j]=='1'){
                    curr[j]+=1;
                }else{
                    curr[j]=0;
                }
            }
            // for(auto it:curr){
            //     cout<<it<<" ";
            // }
           // cout<<endl;
            ans=max(ans,largestRectangleArea(curr));
        }
        return ans;
    }
};