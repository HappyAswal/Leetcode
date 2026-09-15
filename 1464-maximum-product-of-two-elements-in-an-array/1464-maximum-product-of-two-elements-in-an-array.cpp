class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int fmax=nums[0];
        int smax=INT_MIN;
        for(int i=1;i<nums.size();i++){
            if(nums[i]>=fmax){
                smax=fmax;
                fmax=nums[i];
            }
            else if(nums[i]>smax) smax=nums[i];
        }
        int ans=(fmax-1)*(smax-1);
        return ans;
    }
};