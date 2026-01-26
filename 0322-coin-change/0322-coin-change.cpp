class Solution {
public:
    vector<vector<int>>dp;
    int mcoin(int i,int amount,vector<int>& coins){
        if(amount==0) return 0;
        if(i>=coins.size()) return 1e9;
        if(dp[i][amount]!=-1) return dp[i][amount];
        int pick=1e9;
        if(coins[i]<=amount) pick=1+mcoin(i,amount-coins[i],coins);
        int notpick=mcoin(i+1,amount,coins);
        return dp[i][amount]=min(pick,notpick);
    }
    int coinChange(vector<int>& coins, int amount) {
        dp.assign(coins.size(),vector<int>(amount+1,-1));
        int ans=mcoin(0,amount,coins);
        return (ans>=1e9) ? -1:ans;
    }
};