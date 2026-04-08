class Solution {
public:
    int dp[51][51][51][51];
    int n;
    int fxn(int r1,int c1,int r2,int c2,vector<vector<int>>& grid){
        if(r1>=n||r2>=n||c1>=n||c2>=n||grid[r1][c1]==-1 || grid[r2][c2]==-1) return INT_MIN;

        if(dp[r1][c1][r2][c2]!=-1) return dp[r1][c1][r2][c2];

        if(r1==n-1 && c1==n-1) return grid[n-1][n-1];
        int res=grid[r1][c1];
        if(r1!=r2 || c1!=c2) res+=grid[r2][c2];

        int v1=fxn(r1+1,c1,r2+1,c2,grid);
        int v2=fxn(r1,c1+1,r2,c2+1,grid);
        int v3=fxn(r1,c1+1,r2+1,c2,grid);
        int v4=fxn(r1+1,c1,r2,c2+1,grid);
        int mx1=max(v1,v2);
        int mx2=max(v3,v4);
        res+=max(mx1,mx2);
        return dp[r1][c1][r2][c2]=res;    
    }
    int cherryPickup(vector<vector<int>>& grid) {
        n=grid.size();
        memset(dp,-1,sizeof(dp));
        return max(0,fxn(0,0,0,0,grid));
    }
};