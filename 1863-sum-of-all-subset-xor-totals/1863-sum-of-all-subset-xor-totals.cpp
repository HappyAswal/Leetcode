class Solution {
public:
    int solve(int i,vector<int>&nums,int xr){
        if(i==nums.size()) return xr;
        int pick=solve(i+1,nums,xr^nums[i]);
        int npick=solve(i+1,nums,xr);
        return pick+npick;
    }
    int subsetXORSum(vector<int>& nums) {
        return solve(0,nums,0);
    }
};