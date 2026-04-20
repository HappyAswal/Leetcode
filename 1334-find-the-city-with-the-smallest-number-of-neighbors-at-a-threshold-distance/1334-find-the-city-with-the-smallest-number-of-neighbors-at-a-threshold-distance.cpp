class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<pair<int,int>>>adj(n);
        for(auto x:edges){
            adj[x[0]].push_back({x[1],x[2]});
            adj[x[1]].push_back({x[0],x[2]});
        }
        int mcount=INT_MAX;
        int anscity=-1;
        for(int src=0;src<n;src++){
            vector<int>dist(n,INT_MAX);
            priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
            dist[src]=0;
            pq.push({0,src});
            while(!pq.empty()){
                auto [d,node]=pq.top(); pq.pop();
                if(d>dist[node]) continue;
                for(auto x:adj[node]){
                    auto[nn,nd]=x;
                    if(nd+d<dist[nn]){
                        dist[nn]=nd+d;
                        pq.push({dist[nn],nn});
                    }
                }
            }
            int count=0;
            for(int i=0;i<n;i++){
                if(i!=src && dist[i]<=distanceThreshold) count++;
            }
            if(count<=mcount){
                mcount=count;
                anscity=src;
            }
        }
        return anscity;
    }
};