class Solution {
public:
    void solve(int i,vector<int>& ar, set<vector<int>>& st, vector<int>& nums){
        if(i==nums.size()){
            if(ar.size()>1) st.insert(ar);
            return;    
        }
        if(ar.size()==0 || ar.back() <= nums[i]){
            ar.push_back(nums[i]);
            solve(i+1,ar,st,nums);
            ar.pop_back();
            //pop_back
        } 
        solve(i+1,ar,st,nums);
    }
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        vector<int> ar;
        set<vector<int>> st;
        solve(0,ar,st,nums);
        return vector<vector<int>>(st.begin(), st.end());
    }
};