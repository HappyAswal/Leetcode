class Solution {
public:
    vector<int> runningSum(vector<int>& nums) {
        int n=nums.size();
        vector<int>suffix(n);
        suffix[0]=nums[0];
        for(int i=1;i<n;i++){
            suffix[i]=suffix[i-1]+nums[i];
        }
        return suffix;
    }
};