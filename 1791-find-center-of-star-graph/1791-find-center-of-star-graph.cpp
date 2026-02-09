class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        //number of total edges is equal to total nodes-1
        unordered_map<int,int> degree;
        for(auto& node:edges){
            int u=node[0];
            int v=node[1];
            degree[u]++;
            degree[v]++;
        }
        for(auto &it:degree){
            if(it.second==edges.size()){
                return it.first;
            }
        }
        return -1;
    }
};