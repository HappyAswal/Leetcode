class Solution {
public:
    vector<vector<int>>ans;
    vector<int>path;
    int n;
    void dfs(int src,  vector<vector<int>>&graph){
        if(src==n-1){
            ans.push_back(path);
            return;
        }
        for(auto nbr:graph[src]){
            path.push_back(nbr);
            dfs(nbr,graph);
            path.pop_back();
        }
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        n=graph.size();
        path.push_back(0);
        dfs(0,graph);
        return ans;
    }
};