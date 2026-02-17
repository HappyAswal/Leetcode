class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int,int>>> adj(n+1);
        for(auto&x:times){
            int u=x[0];
            int v=x[1];
            int w=x[2];
            adj[u].push_back({v,w});
        }
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        vector<int>dist(n+1,1e9);
        dist[k]=0;
        pq.push({0,k});
        while(!pq.empty()){
            auto x=pq.top(); 
            pq.pop();
            long long currd=x.first;
            int currn=x.second;
            if(currd>dist[currn]) continue;
            for(auto &nbr : adj[currn]){
                int v=nbr.first;
                int w=nbr.second;
                if(currd+w<dist[v]){
                    dist[v]=currd+w;
                    pq.push({dist[v],v});
                }
            }
        }
        int ans;
        for(int i=1;i<=n;i++){
            if(dist[i]==1e9) return -1;
            ans=max(ans,dist[i]);
        }
        return ans;
    }
};