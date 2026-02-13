class Solution {
public:
    vector<vector<int>> dp;
    int minps(vector<vector<int>>& triangle,int i,int j){
        if(i==triangle.size()-1) return triangle[i][j];
        if(dp[i][j]!=INT_MAX) return dp[i][j];
        int dr=minps(triangle,i+1,j+1);
        int d=minps(triangle,i+1,j);
        return dp[i][j]=triangle[i][j]+min(dr,d);
    }
    int minimumTotal(vector<vector<int>>& triangle) {
        dp.assign(triangle.size(),vector<int>(triangle.size(),INT_MAX));
        return minps(triangle,0,0);
    }
};