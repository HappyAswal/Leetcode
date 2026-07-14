class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int n=nums.size();
        vector<int>freq(n+1);
        for(int x:nums){
            freq[x]++;
            if(freq[x]>1) return x;
        } 
        return -1;
    }
};