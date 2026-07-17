class Solution {
public:
    bool check(int rng,vector<int>&nums,int k){
        int count=1;
        int sum=0;
        for(int i=0;i<nums.size();i++){
            if(sum+nums[i]<=rng) sum+=nums[i];
            else{
                sum=nums[i];
                count++;
            }
        }
        return count<=k;
    }
    int splitArray(vector<int>& nums, int k) {
        int low=*max_element(nums.begin(),nums.end());
        int high=accumulate(nums.begin(),nums.end(),0);
        int ans=high;
        while(low<=high){
            int mid=low+(high-low)/2;
            if(check(mid,nums,k)){
                ans=mid;
                high=mid-1;
            }else low=mid+1;
        }
        return ans;
    }
};