class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int i=0,j=0;
        int sum=0;
        int minimal=INT_MAX;
        while(j<nums.size()){
            sum+=nums[j];
            while(sum>=target){
                sum-=nums[i];
                minimal=min(minimal,j-i+1);
                i++;
            }
            j++;
        }
        if(minimal==INT_MAX){
            return 0;
        }
        return minimal;
    }
};