class Solution {
public:
    vector<int> leftRightDifference(vector<int>& nums) {
        int n=nums.size();
        vector<int>ans(n,0);
        
        vector<int>ls(n,0);
        int lsum=nums[0];
        for(int i=1;i<n;i++){
            ls[i]=lsum;
            lsum+=nums[i];
        }

        vector<int>rs(n,0);
        int rsum=nums[n-1];
        for(int i=n-2;i>=0;i--){
            rs[i]=rsum;
            rsum+=nums[i];
        }

        for(int i=0;i<n;i++){
            int val=abs(ls[i]-rs[i]);
            ans[i]=val;
        }
        return ans;
    }
};