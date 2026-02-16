class Solution {
public:
    bool dfs(int clr,int src,vector<int>&color,vector<vector<int>>& dislikes,vector<vector<int>>&adj){
        color[src]=clr;
        for(int v:adj[src]){
            if(color[v]==-1){
                if(!dfs(1-clr,v,color,dislikes,adj)) return false;
            }else if(color[v]==color[src]) return false;
        }
        return true;

    }
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        vector<vector<int>>adj(n+1);
        vector<int>color(n+1,-1);
        for(auto&x:dislikes){
            int u=x[0]; int v=x[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        for(int i=1;i<=n;i++){
            if(color[i]==-1){
                if(!dfs(0,i,color,dislikes,adj)) return false;
            }
        }
        return true;
    }
};