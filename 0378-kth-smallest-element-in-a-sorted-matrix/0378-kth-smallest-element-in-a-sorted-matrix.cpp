class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        vector<int>m;
        for(auto x:matrix){
            for(auto y:x){
                m.push_back(y);
            }
        }
        sort(m.begin(),m.end());
        return m[k-1];
    }
};