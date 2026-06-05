class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        unordered_map<int,int>freq;
        int n=nums.size();
        unordered_set<int>st;
        vector<int>ans;
        for(int x:nums){
            freq[x]++;
            if(freq[x]>n/3) st.insert(x);
        }
        for(int x:st) ans.push_back(x);
        return ans;
    }
};