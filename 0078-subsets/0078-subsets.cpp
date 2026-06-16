class Solution {
public:
    vector<vector<int>>comb;
    void fxn(int i,vector<int>& nums,vector<int>&temp){
        if(i==nums.size()){
            comb.push_back(temp);
            return;
        }
        temp.push_back(nums[i]);
        fxn(i+1,nums,temp);
        temp.pop_back();
        fxn(i+1,nums,temp);

    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int>temp;
        fxn(0,nums,temp);
        return comb;
    }
};