class Solution {
public:
    int countValidSelections(vector<int>& nums) {
        int n=nums.size();
        int result=0;
        int curr=0;
        int s =accumulate(nums.begin(),nums.end(),0);
        //for loop bhi likh sakte ho

        for(int i=0;i<n; i++){
            curr=curr+nums[i];
            int left=curr;
            int right=s-left;
            if(nums[i]!=0) continue;
            if(left==right) result+=2;
            if(abs(left-right)==1) result++;

        }
        return result;
    }
};