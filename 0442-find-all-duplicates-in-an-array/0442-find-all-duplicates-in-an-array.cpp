class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int>ans;
        int n=nums.size();
        vector<int>freq(n+1);
        for(int x:nums){
            freq[x]++;
            if(freq[x]==2) ans.push_back(x);
        }
        return ans;
    }
};