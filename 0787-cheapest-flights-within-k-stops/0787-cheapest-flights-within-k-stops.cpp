class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int,int>>>adj(n);
        for(auto x:flights){
            adj[x[0]].push_back({x[1],x[2]});
        }
        queue<tuple<int,int,int>>q;
        vector<int>dist(n,INT_MAX);
        dist[src]=0;
        //currw,currn,k
        q.push({0,src,0});
        while(!q.empty()){
            auto[currw,currn,ck]=q.front(); q.pop();
            if(ck>k) continue;
            for(auto x:adj[currn]){
                auto[v,w]=x;
                int neww=currw+w;
                if(dist[v]>neww && ck<=k){
                    dist[v]=neww;
                    q.push({neww,v,ck+1});
                }
            }
        }
        return (dist[dst]==INT_MAX)?-1:dist[dst];
    }
};