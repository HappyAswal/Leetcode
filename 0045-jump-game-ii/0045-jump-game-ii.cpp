class Solution {
public:
    vector<int>dp;
    int fxn(int i,vector<int>&nums){
        if(i>=nums.size()-1) return 0;
        if(dp[i]!=-1) return dp[i];
        int jump=1e9;
        for(int j=1;j<=nums[i];j++){
            jump=min(jump,1+fxn(i+j,nums));
        }
        return dp[i]=jump;
    }
    int jump(vector<int>& nums) {
        dp.assign(nums.size(),-1);
        return fxn(0,nums);
    }
};