class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        int mod=1e9+7;
        vector<vector<pair<int,int>>>adj(n);
        for(auto&x:roads){
            adj[x[0]].push_back({x[1],x[2]});
            adj[x[1]].push_back({x[0],x[2]});
        }
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        vector<long long>dist(n,LLONG_MAX);
        vector<long long>ways(n,0);
        int src=0;
        dist[0]=0;
        ways[0]=1;
        pq.push({0,src});
        while(!pq.empty()){
            auto[cost,cn]=pq.top();
            pq.pop();
            if(cost>dist[cn]) continue;
            for(auto&x:adj[cn]){
                auto[v,c]=x;
                long long newcost=cost+c;
                if(newcost<dist[v]){
                    ways[v]=ways[cn];
                    dist[v]=newcost;
                    pq.push({newcost,v});
                }else if(newcost==dist[v]){
                    ways[v]=(ways[v]+ways[cn])%mod;
                }
            }
        }
        return  ways[n-1];
    }
};