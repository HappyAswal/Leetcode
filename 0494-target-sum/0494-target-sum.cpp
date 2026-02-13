class Solution {
public:
    vector<vector<int>> dp;
    int ts;
    int trry(int i,vector<int>&nums,int target,int sum){
        if(i==nums.size()) return target==sum;
        if(dp[i][sum+ts]!=-1) return dp[i][sum+ts];
        int w1=trry(i+1,nums,target,sum+nums[i]);
        int w2=trry(i+1,nums,target,sum-nums[i]);
        return dp[i][sum+ts]=w1+w2;
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        ts=accumulate(nums.begin(),nums.end(),0);
        dp.assign(nums.size(),vector<int>(2*ts+1,-1));

        return trry(0,nums,target,0);
    }
};