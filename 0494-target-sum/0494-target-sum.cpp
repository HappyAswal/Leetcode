class Solution {
public:
    int solve(int i,vector<int>&nums,int sum,int target){
        if(target==sum && i==nums.size()) return 1;
        if(target!=sum && i==nums.size()) return 0;
        int pickp=solve(i+1,nums,sum+nums[i],target);
        int pickm=solve(i+1,nums,sum-nums[i],target);
        return pickp+pickm;
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        return solve(0,nums,0,target);
    }
};