class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n=heights.size();
        //right smaller nearest
        //store index
        vector<int>rs(n);
        //left smaller nearest
        vector<int>ls(n);
        stack<int>st;
        for(int i=n-1;i>=0;i--){
            while(st.size()>0 && heights[st.top()]>=heights[i]){
                st.pop();
            }
            rs[i]=(st.size()==0)? n:st.top();
            st.push(i);
        }
        while(!st.empty()) st.pop();
        for(int i=0;i<n;i++){
            while(st.size()>0 && heights[st.top()]>=heights[i]){
                st.pop();
            }
            ls[i]=(st.size()==0)?-1:st.top();
            st.push(i);
        }
        int max_area=0;
        for(int i=0;i<n;i++){
            int width= rs[i]-ls[i]-1;
            int area=heights[i] * width;
            if(area>max_area) max_area=area;
        }
        return max_area;
    }
};