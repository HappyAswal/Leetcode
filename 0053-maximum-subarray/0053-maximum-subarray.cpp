class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int csum=0;
        int ans=INT_MIN;
        for(int x:nums){
            csum+=x;
            ans=max(csum,ans);
            if(csum<0){
                csum=0;
            }
        }
        return ans;
    }
};