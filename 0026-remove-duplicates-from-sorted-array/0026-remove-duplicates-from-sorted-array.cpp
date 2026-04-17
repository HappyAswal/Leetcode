class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int idx=0;
        int n=nums.size();
        for(int j=1;j<n;j++){
            if(nums[j]!=nums[idx]){
                idx++;
                swap(nums[idx],nums[j]);
            }
        }
        return idx+1;
    }
};