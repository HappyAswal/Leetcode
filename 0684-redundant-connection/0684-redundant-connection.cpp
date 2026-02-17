class Solution {
public:
    bool dfs(int i,int target,vector<vector<int>>&adj,vector<bool>&vis){
        if(i==target) return true;
        vis[i]=true;
        for(auto&nbr:adj[i]){
            if(!vis[nbr]){
                if(dfs(nbr,target,adj,vis)) return true;
            }
        }
        return false;
    }
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n=edges.size();
        vector<vector<int>>adj(n+1);
        for(auto&x:edges){
            int u=x[0];
            int v=x[1];
            vector<bool>vis(n+1,false);

            if(dfs(u,v,adj,vis)) return x;

            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        return {};
    }
};