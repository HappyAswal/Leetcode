class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int,int>freq;
        if(nums1.size()<nums2.size()) swap(nums1,nums2);
        vector<int>ans;
        for(int x:nums1) freq[x]++;
        for(int x:nums2){
            if(freq[x]>=1){
                ans.push_back(x);
                freq[x]--;
            }
        }
        return ans; 
    }
};