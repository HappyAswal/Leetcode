class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int,int>freq;
        if(nums1.size()<nums2.size()) swap(nums1,nums2);

        for(int x:nums1) freq[x]++;
        unordered_set<int>st;
        for(int x:nums2){
            if(freq[x]>=1){
                st.insert(x);
                freq[x]--;
            }
        }
        vector<int>ans;
        for(auto x:st) ans.push_back(x);
        return ans;
    }
};