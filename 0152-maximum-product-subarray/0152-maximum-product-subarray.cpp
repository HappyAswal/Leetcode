class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n=nums.size();
        int mx=INT_MIN;
        for(int i=0;i<n;i++){
            for(int j=i;j<n;j++){
                int prod=1;
                for(int k=i;k<=j;k++){
                    prod*=nums[k];
                }
                mx=max(mx,prod);
            }
        }
        return mx;
    }
};