class dsu{
    public:
    vector<int>parent,size;
    int component,best;
    dsu(int n){
        parent.resize(n+1);
        size.resize(n+1,1);
        this->component=n;
        best=1;
        for(int i=1;i<=n;i++) parent[i]=i;
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
            best=max(best,size[px]);
        }else{
            parent[px]=py;
            size[py]+=size[px];
            best=max(best,size[py]);
        }
        component--;
    }
};
class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        vector<vector<int>>edges;
        int n=points.size();
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                int dist=abs(points[i][0]-points[j][0])+abs(points[i][1]-points[j][1]);
                edges.push_back({i,j,dist});
            }
        }
        sort(edges.begin(),edges.end(),[](auto&a,auto&b){
            return a[2]<b[2];
        });
        dsu d(n);
        int cost=0;
        for(auto&x:edges){
            int u=x[0],v=x[1],c=x[2];
            if(d.find(u)!=d.find(v)){
                d.union_m(u,v);
                cost+=c;
            }
        }
        return cost;
    }
};