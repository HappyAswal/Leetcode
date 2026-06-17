class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int,int>>>adj(n);
        for(auto x:flights){
            adj[x[0]].push_back({x[1],x[2]});
        }

        vector<int>dist(n,1e9);
        queue<tuple<int,int,int>>q;
        //stops,node,dist
        q.push({0,src,0});
        dist[src]=0;
        while(!q.empty()){
            auto[stp,node,d]=q.front(); q.pop();
            if(stp>k) continue;
            for(auto x:adj[node]){
                auto[u,w]=x;
                if(dist[u]>w+d){
                    dist[u]=w+d;
                    q.push({stp+1,u,dist[u]});
                }
            }

        }
        return dist[dst]>=1e9?-1:dist[dst];
    }
};