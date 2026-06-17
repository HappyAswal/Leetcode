class Solution {
public:
    vector<int>dp;
    int fxn(int i,vector<int>&nums){
        if(i>=nums.size()) return 0;
        if(dp[i]!=-1) return dp[i];
        int rb1=nums[i]+fxn(i+2,nums);
        int rb2=fxn(i+1,nums);
        return dp[i]=max(rb1,rb2);
    }
    int rob(vector<int>& nums) {
        dp.assign(nums.size(),-1);
        return fxn(0,nums);
    }
};