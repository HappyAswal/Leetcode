class Solution {
public:
    int nxtg(int i,vector<int>& nums2){
        for(int j=i+1;j<nums2.size();j++){
            if(nums2[j]>nums2[i]) return nums2[j];
        }
        return -1;
    }
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        int n1=nums1.size(),n2=nums2.size();
        vector<int> ans;
        for(int i=0;i<n1;i++){
            for(int j=0;j<n2;j++){
                if(nums1[i]==nums2[j]){
                    ans.push_back(nxtg(j,nums2));
                }
            }
        }
        return ans;
    }
};