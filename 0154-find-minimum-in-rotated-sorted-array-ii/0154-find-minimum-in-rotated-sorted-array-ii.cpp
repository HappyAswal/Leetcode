class Solution {
public:
    int findMin(vector<int>& nums) {
        int x=INT_MAX;
        for(int i=0;i<nums.size();i++){
            if(nums[i]<x) x=nums[i];
        }
        return x;
    }
};