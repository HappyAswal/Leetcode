class Solution {
public:
    int mx=-1;
    void dfs(int src,vector<vector<int>>&adj,vector<bool>&vis,vector<bool>&path,vector<int>&depth){
        vis[src]=1;
        path[src]=1;
        for(auto&x:adj[src]){
            if(!vis[x]){
                depth[x]=depth[src]+1;
                dfs(x,adj,vis,path,depth);
            }else if(path[x]){
                mx=max(mx,depth[src]-depth[x]+1);
            }
        }
        path[src]=0;
    }
    int longestCycle(vector<int>& edges) {
        int n=edges.size();
        vector<vector<int>>adj(n);
        for(int i=0;i<n;i++){
            if(edges[i]!=-1){
                adj[i].push_back(edges[i]);
            }
        }
        vector<bool>vis(n,false);
        vector<bool>path(n,false);
        vector<int>depth(n,0);
        for(int i=0;i<n;i++){
            depth[i]=0;
            if(!vis[i]) dfs(i,adj,vis,path,depth);
        }
        return mx;
    }
};