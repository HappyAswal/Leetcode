class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int>s1(nums1.begin(),nums1.end()),s2(nums2.begin(),nums2.end());
        unordered_set<int>temp1,temp2;
        for(int x:s1){if(!s2.count(x)){ temp1.insert(x);}}
        for(int x:s2){if(!s1.count(x)){ temp2.insert(x);}}
        return {vector<int>(temp1.begin(),temp1.end()),vector<int>(temp2.begin(),temp2.end())};

    }
};