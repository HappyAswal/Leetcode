class dsu{
    public:
        vector<int>parent,size;
        int component;
        dsu(int n){
            parent.resize(n+1);
            size.resize(n+1,1);
            this->component=n;
            for(int i=0;i<=n;i++) parent[i]=i;
        }
        int find(int x){
            if(parent[x]==x) return x;
            return parent[x]=find(parent[x]);
        }
        void union_m(int x,int y){
            int px=find(x);
            int py=find(y);
            if(px==py) return;
            if(size[px]>=size[py]){
                parent[py]=px;
                size[px]+=size[py];
            }else if(size[px]<size[py]){
                parent[px]=py;
                size[py]+=size[px];
            }
            component--;
        }
};
class Solution {
public:
    int makeConnected(int n, vector<vector<int>>& connections) {
        dsu d(n);
        int cables=0;
        for(auto&x:connections){
            int u=x[0],v=x[1];
            if(d.find(u)==d.find(v)) cables++;
            d.union_m(u,v);
        }
        int comp=d.component;
        if(cables>=comp-1) return comp-1;
        return -1;
    }
};