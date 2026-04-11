class Solution {
public:
    int minimumDistance(vector<int>& nums) {
        int n=nums.size();
        unordered_map<int,vector<int>>mp;
        int ans=INT_MAX;
        for(int i=0;i<n;i++){
            mp[nums[i]].push_back(i);
        }
        for(auto &x:mp){
            auto v=x.second;
            if(v.size()<3) continue;
            sort(v.begin(),v.end());
            for(int i=0;i+2<v.size();i++){
                int val=2*(v[i+2]-v[i]);
                ans=min(ans,val);
            }
        }
        return (ans==INT_MAX)?-1:ans;
    }
};