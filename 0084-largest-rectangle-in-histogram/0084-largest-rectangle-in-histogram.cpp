class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        
        stack<int> str;
        stack<int> stl;
        int n=heights.size();
       // int mn=*min_element(heights.begin(),heights.end());
        vector<int> l(n,-1);
        vector<int> r(n,-1);
        for(int i=n-1;i>=0;i--){
            while(!str.empty() && heights[str.top()]>=heights[i]){
                str.pop();
            }
            if(!str.empty()){
                r[i]=str.top();
            }
            str.push(i);
            
        }
        for(int i=0;i<n;i++){
            while(!stl.empty() && heights[stl.top()]>=heights[i]){
                stl.pop();
            }
            if(!stl.empty()){
                l[i]=stl.top();
            }
            stl.push(i);
            
        }
             int ans=0;
        for(int i=0;i<n;++i){
            
                 if(l[i]==(-1)){
                l[i]=-1;
            }
             if(r[i]==(-1)){
                r[i]=n;
            }
            
            int h=heights[i]*(r[i]-l[i]-1);
            ans=max(ans,h);
           // cout<<h<<" "<<i<<" "<<l[i]<<" "<<r[i]<<endl;
        }
       
       return ans;
    }
};