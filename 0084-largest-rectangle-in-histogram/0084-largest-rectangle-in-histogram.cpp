class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n=heights.size();
        vector<int>ls(n);
        stack<int>st;
        for(int i=0;i<n;i++){
            while(!st.empty() && heights[st.top()]>=heights[i]){st.pop();}
            ls[i]=st.empty()?-1:st.top();
            st.push(i);
        }
        vector<int>rs(n);
        while(!st.empty()) st.pop();
        for(int i=n-1;i>=0;i--){
            while(!st.empty() && heights[st.top()]>=heights[i]){st.pop();}
            rs[i]=st.empty()?n:st.top();
            st.push(i);
        }
        int max_area=0;
        for(int i=0;i<n;i++){
            int width=rs[i]-ls[i]-1;
            int area=heights[i]*width;
            max_area=max(area,max_area);
        }
        return max_area;
    }
};