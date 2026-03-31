class Solution {
public:
    bool check(int mid,vector<int>& nums,int k){
        int sum=0;
        int count=1;
        for(int i=0;i<nums.size();i++){
            if(sum+nums[i]>mid){
                count++;
                sum=nums[i];
            }
            else sum+=nums[i];
        }
        return count<=k;
    }
    int splitArray(vector<int>& nums, int k) {
        int start=*max_element(nums.begin(),nums.end());
        int end=accumulate(nums.begin(),nums.end(),0);
        int ans;
        while(start<=end){
            int mid=start+(end-start)/2;
            if(check(mid,nums,k)){
                ans=mid;
                end=mid-1;
            }else start=mid+1;
        }
        return ans;
    }
};