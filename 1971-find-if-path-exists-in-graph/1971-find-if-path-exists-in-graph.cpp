class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        if(source==destination) return true;

        vector<vector<int>>adj(n);
        for(auto&x:edges){
            int u=x[0];
            int v=x[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        queue<int>q;
        vector<bool>vis(n,false);

        q.push(source);
        vis[source]=true;

        while(!q.empty()){
            int f=q.front();
            q.pop();
            for(auto&nbr:adj[f]){
                if(!vis[nbr]){
                    if(nbr==destination) return true;
                    vis[nbr]=true;
                    q.push(nbr);
                }
            }
        }
        return false;
    }
};