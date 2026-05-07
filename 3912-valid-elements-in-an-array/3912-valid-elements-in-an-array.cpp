class Solution {
public:
    vector<int> findValidElements(vector<int>& nums) {
        int n=nums.size();
        if(n==1) return nums;
        vector<int>ans;
        for(int i=0;i<n;i++){
            int num=nums[i];
            bool flag1=true;
            bool flag2=true;
            for(int j=0;j<i;j++){
                if(nums[j]>=num){
                    flag1=false;
                    break;
                }
            }
            for(int k=i+1;k<n;k++){
                if(nums[k]>=num){
                    flag2=false;
                    break;
                }
            }
            if(flag1||flag2) ans.push_back(num);
        }
        return ans;
    }
};