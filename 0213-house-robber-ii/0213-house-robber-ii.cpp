class Solution {
public:
    vector<int>dp;
    int maxmoney(vector<int>& nums,int i,int lasthouse){
        if(i>lasthouse) return 0;
        if(i>=nums.size()) return 0;
        if(dp[i]!=-1) return dp[i];
        int pick=nums[i]+maxmoney(nums,i+2,lasthouse);
        int notpick=maxmoney(nums,i+1,lasthouse);
        return dp[i]=max(pick,notpick);
    }
    int rob(vector<int>& nums) {
        int n=nums.size();
        if(n==1) return nums[0];
        dp.assign(nums.size(),-1);
        int house1=maxmoney(nums,0,n-2);

        dp.assign(nums.size(),-1);
        int house2=maxmoney(nums,1,n-1);

        return max(house1,house2);
    }

};