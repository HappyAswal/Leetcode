class Solution {
public:
    vector<vector<int>>dp;
    int total;
    int solve(int i,vector<int>&nums,int sum,int target){
        if(i==nums.size()) return target==sum;
        if(dp[i][sum+total]!=-1) return dp[i][sum+total];
        int pickp=solve(i+1,nums,sum+nums[i],target);
        int pickm=solve(i+1,nums,sum-nums[i],target);
        return dp[i][sum+total]=pickp+pickm;
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        total=accumulate(nums.begin(),nums.end(),0);
        dp.assign(nums.size(),vector<int>(2*total+1,-1));
        return solve(0,nums,0,target);
    }
};