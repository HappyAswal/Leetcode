class Solution {
public:
    vector<int>dp;
    bool fxn(int i,vector<int>&nums){
        if(i>=nums.size()-1) return true ;
        if(dp[i]!=-1) return dp[i];
        for(int j=1;j<=nums[i];j++){
            if(fxn(i+j,nums)) return dp[i]=1; 
        }
        return dp[i]=0;
    }
    bool canJump(vector<int>& nums) {
        dp.assign(nums.size(),-1);
        return fxn(0,nums);
    }
};