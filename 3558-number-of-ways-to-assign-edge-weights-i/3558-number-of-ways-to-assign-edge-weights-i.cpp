class Solution {
public:
    int max_depth=0;
    int MOD=1e9+7;
    long long power(long long a,int n){
        long long ans=1;
        while(n>0){
            if(n%2==1){
                ans=(ans*a)%MOD;
                n=n-1;
            }else{
                a=(a*a)%MOD;
                n=n/2;
            }
        }
        return ans;
    }
    void maxdepth(int depth,int node,int parent,vector<vector<int>>&adj){
        max_depth=max(max_depth,depth);
        for(auto nbr: adj[node]){
            if(nbr==parent) continue;
            maxdepth(depth+1,nbr,node,adj);
        }
    }
    int assignEdgeWeights(vector<vector<int>>& edges) {
        //node=edges+1
        int n=edges.size()+1;
        vector<vector<int>>adj(n+1);
        for(auto x:edges){
            int u=x[0],v=x[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        int depth=0;
        maxdepth(depth,1,-1,adj);
        if(max_depth==0) return 1;
        return power(2,max_depth-1)%MOD;
    }
};