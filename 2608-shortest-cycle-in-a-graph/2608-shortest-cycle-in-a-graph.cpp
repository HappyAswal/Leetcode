class Solution {
public:
    int findShortestCycle(int n, vector<vector<int>>& edges) {
        int mn=INT_MAX;
        vector<vector<int>>adj(n);
        for(auto&x:edges){
            int u=x[0],v=x[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        
        for(int i=0;i<n;i++){
            vector<int>depth(n,0);
            vector<bool>vis(n,false);
            queue<pair<int,int>>q;
            q.push({i,-1});
            while(!q.empty()){
                auto r=q.front(); q.pop();
                int src=r.first,parent=r.second;
                vis[src]=1;
                for(auto&x:adj[src]){
                    if(!vis[x]){
                        depth[x]=depth[src]+1;
                        q.push({x,src});
                    }else if(vis[x] && x!=parent){
                        mn=min(mn,depth[src]+depth[x]+1);
                    }
                }
            }
        }
        return (mn==INT_MAX)?-1:mn;
    }
};