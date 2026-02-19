class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int,int>>>adj(n);
        for(auto&x:flights){
            int u=x[0], v=x[1], w=x[2];
            adj[u].push_back({v,w});
        }
        queue<tuple<int,int,int>>q;
        vector<int>dist(n,INT_MAX);
        dist[src]=0;
        q.push({0,src,0});
        
        while(!q.empty()){
            auto[currw,currn,stops]=q.front();
            q.pop();
            if(stops>k) continue;
            for(auto&nbr:adj[currn]){
                auto[v,w]=nbr;
                int neww=currw+w;
                if(dist[v]>neww && stops<=k){
                    dist[v]=neww;
                    q.push({neww,v,stops+1});
                }

            }
        }
        if(dist[dst]==INT_MAX) return -1;
        return dist[dst];
    }
};