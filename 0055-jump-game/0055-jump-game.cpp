class Solution {
public:
    bool canJump(vector<int>& nums) {
        int maxj=0;
        for(int i=0;i<nums.size();i++){
            if(i>maxj) return false;
            maxj=max(maxj,i+nums[i]);
        }
        return 0==0;
    }
};