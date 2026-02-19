class Solution {
public:
    int n,m;
    int mod=1e9+7;
    vector<vector<int>>dp;
    int dx[4]={1,-1,0,0};
    int dy[4]={0,0,-1,1};
    int dfs(int i,int j,vector<vector<int>>& grid){
        if(dp[i][j]!=-1) return dp[i][j];
        long long count=1;
        for(int k=0;k<4;k++){
            int ni=i+dx[k];
            int nj=j+dy[k];
            if(ni>=0 && nj>=0 && ni<n && nj<m && grid[ni][nj]>grid[i][j]){
                count=(count+dfs(ni,nj,grid))%mod;
            }
        }
        return dp[i][j]=count;
    }
    int countPaths(vector<vector<int>>& grid) {
        n=grid.size();
        m=grid[0].size();
        dp.assign(n,vector<int>(m,-1));
        long long ans=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                ans=(ans+dfs(i,j,grid))%mod;
            }
        }
        return ans;
    }
};