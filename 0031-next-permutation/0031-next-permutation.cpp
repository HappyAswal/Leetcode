class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        //finding the break point
        //         i  i+1
        //number 2 1  5   4 3 0 0

        //here bp is 1
        int n=nums.size();
        int bp=-1;
        for(int i=n-2;i>=0;i--){
            if(nums[i]<nums[i+1]){
                bp=i;
                break;
            }
        }
        //if all increasing from end and no dip that means we can just rev and get the smallest
        // eg 8 4 3 1 0 0 bp=-1 as no dip
        // reverse 0 0 1 3 4 8 next permutation
        if(bp==-1){
            reverse(nums.begin(),nums.end());
            return;
        }

        //as graph <-- increasing if we find the next first number greater than nums[bp]
        //that will be smallest
        for(int i=n-1;i>bp;i--){
            if(nums[i]>nums[bp]){
                swap(nums[i],nums[bp]);
                break;
            }
        }
        reverse(nums.begin()+bp+1,nums.end());
        //number becomes 2 3 [5 4 1 0 0] we can rev this and get 0 0 1 4 5 smallest
    }
};