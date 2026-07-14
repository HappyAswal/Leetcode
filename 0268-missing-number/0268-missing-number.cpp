class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n=nums.size();
        int freq[10001]={0};
        for(int i=0;i<nums.size();i++){freq[nums[i]]++;}
        for(int i=0;i<=n;i++){
            if(freq[i]==0) return i;
        }
        return -1;
    }
};