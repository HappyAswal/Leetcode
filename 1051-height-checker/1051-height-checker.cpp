class Solution {
public:
    int heightChecker(vector<int>& heights) {
        int n=heights.size();
        int count=0;
        vector<int> check=heights;
        sort(check.begin(),check.end());
        for(int i=0;i<n;i++){
            if(check[i]!=heights[i]) count++;
        }
        return count;
    }
};