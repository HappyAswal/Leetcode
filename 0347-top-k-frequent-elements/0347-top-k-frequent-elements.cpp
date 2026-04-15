class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int>freq;
        for(auto x:nums) freq[x]++;
        vector<pair<int,int>>val;
        for(auto x:freq){
            val.push_back({x.first,x.second});
        }
        sort(val.begin(),val.end(),[](auto&a,auto&b){
            return a.second>b.second;
        });
        
        vector<int>ans;
        for(int i=0;i<k;i++){
            ans.push_back(val[i].first);
        }
        return ans;
    }
};