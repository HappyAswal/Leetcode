class Solution {
public:
    //dfs1
    vector<vector<int>>adj;
    vector<int>dp;
    vector<int>sub;
    vector<int>res;
    int nn;
    void dfs2(int node,int parent){
        for(auto&v:adj[node]){
            if(v!=parent){
                res[v]=res[node]+(nn-sub[v])-sub[v];
                dfs2(v,node);
            }
        }
    }
    void dfs1(int node,int parent){
        //dp[node]=0;
        //sub[node]=1;
        for(int v:adj[node]){
            if(v!=parent){
                dfs1(v,node);
                sub[node]+=sub[v];
                dp[node]+=(dp[v]+sub[v]);
            }
        }
    }
    vector<int> sumOfDistancesInTree(int n, vector<vector<int>>& edges) {
        nn=n;
        dp.assign(n,0);
        sub.assign(n,1);
        adj.resize(n);
        res.resize(n);

        for(auto x:edges){
            int a=x[0],b=x[1];
            adj[a].push_back(b);
            adj[b].push_back(a);
        }
        dfs1(0,-1);
        res[0]=dp[0];
        dfs2(0,-1);
        return res;
    }
};