class Solution {
public:
    vector<vector<int>>dp;
    int solve(int i,vector<int>&coins,int amount){
        if(i>=coins.size()) return 1e9;
        if(amount==0) return 0;
        if(dp[i][amount]!=-1) return dp[i][amount];
        int pick=1e9;
        if(coins[i]<=amount){
            pick=1+solve(i,coins,amount-coins[i]);
        }
        int notpick=solve(i+1,coins,amount);
        return dp[i][amount]=min(pick,notpick);
    }
    int coinChange(vector<int>& coins, int amount) {
        dp.assign(coins.size(),vector<int>(amount+1,-1));
        int ans=solve(0,coins,amount); 
        return (ans>=1e9)?-1:ans;
    }
};