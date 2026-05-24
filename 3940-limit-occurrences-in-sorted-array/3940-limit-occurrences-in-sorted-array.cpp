class Solution {
public:
    vector<int> limitOccurrences(vector<int>& nums, int k) {
        vector<int>ans;
        int i=0;
        int count=1;
        while(i<nums.size()){
            while(i+1<nums.size() && nums[i]==nums[i+1]){
                i++;
                count++;
            }
            int e=(count<=k)?count:k;
            for(int j=1;j<=e;j++){
                ans.push_back(nums[i]);
            }
            i++;
            count=1;
        }
        return ans;
    }
};