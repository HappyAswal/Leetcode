class dsu{
    public:
    vector<int>parent,size;
    dsu(int n){
        parent.resize(n+1);
        size.resize(n+1,1);
        for(int i=0;i<=n;i++) parent[i]=i;
    }
    int find(int x){
        if(parent[x]==x) return x;
        return parent[x]=find(parent[x]);
    }
    vector<int> union_m(int x,int y){
        int px=find(x);
        int py=find(y);
        if(px==py) return{x,y};
        if(size[px]>=size[py]){
            parent[py]=px;
            size[px]+=size[py];
        }else if(size[px]<size[py]){
            parent[px]=py;
            size[py]+=size[px];
        }
        return {};
    }
};
class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n=edges.size();
        dsu d(n);
        for(auto&x:edges){
            int u=x[0];
            int v=x[1];
            if(!d.union_m(u,v).empty()) return d.union_m(u,v) ;
        }
        return {};
    }
};