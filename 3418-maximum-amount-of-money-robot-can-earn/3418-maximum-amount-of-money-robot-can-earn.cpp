class Solution {
public:
    vector<vector<vector<int>>>dp;
    int n,m;
    int solve(int i,int j,int np,vector<vector<int>>& coins){
        if(i>=n||j>=m) return INT_MIN;
        if(i==n-1 && j==m-1){
            if(coins[i][j]<0 && np>0) return 0;
            return coins[i][j];
        }
        if(dp[i][j][np]!=INT_MIN) return dp[i][j][np];
        int take=coins[i][j]+max(solve(i+1,j,np,coins),solve(i,j+1,np,coins));
        int skip=INT_MIN;
        if(coins[i][j]<0 && np>0){
            int r=solve(i+1,j,np-1,coins);
            int d=solve(i,j+1,np-1,coins);
            skip=max(r,d);
        }
        return dp[i][j][np]=max(take,skip);

    }
    int maximumAmount(vector<vector<int>>& coins) {
        //right down
        n=coins.size(),m=coins[0].size();
        dp.assign(n,vector<vector<int>>(m,vector<int>(3,INT_MIN)));

        return solve(0,0,2,coins);
    }
};