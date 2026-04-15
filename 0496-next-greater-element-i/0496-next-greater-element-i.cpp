class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        stack<int>s;
        unordered_map<int,int>ng;
        for(int i=nums2.size()-1;i>=0;i--){
            while(s.size()>0 && nums2[i]>s.top()){
                s.pop();
            }
            if(s.size()) ng[nums2[i]]=s.top();
            else ng[nums2[i]]=-1;
            s.push(nums2[i]);
        }
        vector<int>ans;
        for(int i=0;i<nums1.size();i++){
            ans.push_back(ng[nums1[i]]);
        }
        return ans;
    }
};