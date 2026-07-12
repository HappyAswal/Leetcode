class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        vector<int>temp=arr;
        vector<int>ans;
        sort(temp.begin(),temp.end());
        unordered_map<int,int>mp;
        int rank=1;
        for(int x:temp){
            if(!mp.count(x)){
                mp[x]=rank++;
            }
        }
        for(int x:arr){
            ans.push_back(mp[x]);
        }
        return ans;
    }
};