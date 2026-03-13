class Solution {
public:
    vector<vector<int>>dp;
    int target;
    bool solve(int i,int sum1,vector<int>&nums){
        if(sum1==target) return true;
        if(i>=nums.size()) return false;
        if(dp[i][sum1]!=-1) return dp[i][sum1];
        bool p=false;
        if(nums[i]+sum1<=target){
            p=solve(i+1,sum1+nums[i],nums);
        }
        bool np=solve(i+1,sum1,nums);
        return dp[i][sum1]=p||np;
    }
    bool canPartition(vector<int>& nums) {
        int total=accumulate(nums.begin(),nums.end(),0);
        if(total%2!=0) return false;
        else target=total/2;
        dp.assign(nums.size(),vector<int>(target+1,-1));
        return solve(0,0,nums);
    }
};