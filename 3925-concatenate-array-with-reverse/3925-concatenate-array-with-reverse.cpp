class Solution {
public:
    vector<int> concatWithReverse(vector<int>& nums) {
        vector<int>temp=nums;
        reverse(nums.begin(),nums.end());
        temp.insert(temp.end(),nums.begin(),nums.end());
        return temp;
    }

};