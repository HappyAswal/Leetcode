class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int left=0,right=0;
        while(right<nums.size()){
            int count=1;
            while(right+1<nums.size() && nums[right]==nums[right+1]){
                right++;
                count++;
            }
            int c_num=min(2,count);
            for(int i=0;i<c_num;i++){
                nums[left]=nums[right];
                left++;
            }
            right++;
        }
        return left;
    }
};