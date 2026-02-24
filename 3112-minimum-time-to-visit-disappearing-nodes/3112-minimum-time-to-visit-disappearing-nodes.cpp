class Solution {
public:
    vector<int> minimumTime(int n, vector<vector<int>>& edges, vector<int>& disappear) {
        vector<vector<pair<int,int>>>adj(n);
        for(auto&x:edges){
            adj[x[0]].push_back({x[1],x[2]});
            adj[x[1]].push_back({x[0],x[2]});
        }
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        int src=0;
        vector<int>dist(n,1e9);
        dist[src]=0;
        pq.push({0,src});
        while(!pq.empty()){
            auto[currd,currn]=pq.top();pq.pop();
            if(currd>dist[currn]) continue;
            for(auto&nbr:adj[currn]){
                auto[v,d]=nbr;
                if(currd+d<dist[v] && disappear[v]>currd+d){
                    dist[v]=currd+d;
                    pq.push({dist[v],v});
                }
            }
        }
        for(auto&d:dist){if(d==1e9) d=-1;}
        return dist;
    }
};