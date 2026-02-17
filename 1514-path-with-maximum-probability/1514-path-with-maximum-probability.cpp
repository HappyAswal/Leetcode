class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start_node, int end_node) {
        vector<vector<pair<int,double>>> adj(n);
        for(int i=0;i<edges.size();i++){
            int u=edges[i][0];
            int v=edges[i][1];
            double p=succProb[i];
            adj[u].push_back({v,p});
            adj[v].push_back({u,p});
        }
        priority_queue<pair<double,int>>pq;
        vector<double>dist(n,0.0);
        dist[start_node]=1.0;
        pq.push({1.0,start_node});
        while(!pq.empty()){
            auto x=pq.top(); 
            pq.pop();
            double currd=x.first;
            int currn=x.second;
            if(currd<dist[currn]) continue;
            for(auto &nbr : adj[currn]){
                int v=nbr.first;
                double w=nbr.second;
                if(currd*w>dist[v]){
                    dist[v]=currd*w;
                    pq.push({dist[v],v});
                }
            }
        }
        return dist[end_node];
    }
};