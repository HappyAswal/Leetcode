class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& og) {
        int n=og.size();
        int m=og[0].size();
        vector<vector<int>>dp(n,vector<int>(m,0));

        int i=0;
        while(i<n && og[i][0]!=1){
            dp[i][0]=1;
            i++;
        }
        int j=0;
        while(j<m && og[0][j]!=1){
            dp[0][j]=1;
            j++;
        }
        for(int i=1;i<n;i++){
            for(int j=1;j<m;j++){
                if(og[i][j]!=1){
                    dp[i][j]=dp[i][j-1]+dp[i-1][j];
                }
            }
        }
        return dp[n-1][m-1];
    }
};