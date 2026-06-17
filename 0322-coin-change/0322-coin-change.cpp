class Solution {
public:
    vector<vector<int>>dp;
    int fxn(int i,vector<int>&coins,int amount){
        if(amount==0) return 0;
        if(i>=coins.size() || amount<0) return 1e9;
        if(dp[i][amount]!=-1) return dp[i][amount];
        int pick=1+fxn(i,coins,amount-coins[i]);
        int npick=fxn(i+1,coins,amount);
        return dp[i][amount]=min(pick,npick);
    }
    int coinChange(vector<int>& coins, int amount) {
        dp.assign(coins.size(),vector<int>(amount+1,-1));
        int ans=fxn(0,coins,amount);
        return (ans>=1e9)?-1:ans;
    }
};