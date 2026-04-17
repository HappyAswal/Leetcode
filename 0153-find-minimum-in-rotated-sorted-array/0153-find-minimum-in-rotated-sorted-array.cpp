class Solution {
public:
    int findMin(vector<int>& nums) {
        int left=0;
        int right=nums.size()-1;
        int ans=INT_MAX;
        while(left<=right){
            int mid=left+(right-left)/2;
            if(nums[mid]>=nums[right]){
                ans=min(ans,nums[mid]);
                left=mid+1;
            }else{
                right=mid;
            }
        }
        return ans;
    }
};