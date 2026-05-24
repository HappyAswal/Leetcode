class Solution {
public:
    vector<int> limitOccurrences(vector<int>& nums, int k) {
        vector<int>ans;
        unordered_map<int,int>freq;
        for(int x:nums){
            freq[x]++;
            if(freq[x]<=k){
                ans.push_back(x);
            }
        }
        return ans;
    }
};