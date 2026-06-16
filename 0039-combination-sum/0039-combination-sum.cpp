class Solution {
public:
    vector<vector<int>>combinations;
    void fxn(int i,vector<int>& candidates, int target,vector<int>& temp){
        if(target==0){
            combinations.push_back(temp);
            return;
        }
        if(i==candidates.size()|| target<0) return;
        temp.push_back(candidates[i]);
        fxn(i,candidates,target-candidates[i],temp);
        temp.pop_back();
        fxn(i+1,candidates,target,temp);
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int>temp;
        fxn(0,candidates,target,temp);
        return combinations;
    }
};