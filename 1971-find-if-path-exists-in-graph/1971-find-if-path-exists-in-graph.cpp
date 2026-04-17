class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        vector<vector<int>>adj(n);
        for(auto x:edges){
            adj[x[0]].push_back(x[1]);
            adj[x[1]].push_back(x[0]);
        }
        vector<int>vis(n,false);
        queue<int>q;
        q.push(source);
        vis[source]=true;
        while(!q.empty()){
            int node=q.front(); q.pop();
            if(node==destination) return true;
            for(auto nbr: adj[node]){
                if(!vis[nbr]){
                    q.push(nbr);
                    vis[nbr]=true;
                }
            }
        }
        return false;
    }
};