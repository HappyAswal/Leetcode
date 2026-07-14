class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
       unordered_set<int>st;
        unordered_map<int,int>freq;
        for(int x:nums1) freq[x]++;
        for(int x:nums2){
            if(freq[x]>=1) st.insert(x);
        }
        vector<int>ans(st.begin(),st.end());
        return ans;
    }
};