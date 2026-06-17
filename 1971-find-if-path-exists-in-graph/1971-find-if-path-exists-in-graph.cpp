class Solution {
public:
    vector<bool>vis;
    void dfs(int src,vector<vector<int>>& adj){
        vis[src]=true;
        for(auto nbr:adj[src]){
            if(!vis[nbr]){
                dfs(nbr,adj);
            }
        }
    }
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        if(source==destination) return true;
        vis.assign(n,false);
        vector<vector<int>>adj(n);
        for(auto x:edges){
            adj[x[0]].push_back(x[1]);
            adj[x[1]].push_back(x[0]);
        }
        dfs(source,adj);
        return vis[destination];
    }
};