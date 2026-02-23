class dsu{
    public:
    vector<int>parent,size;
    int component;
    dsu(int n){
        parent.resize(n);
        size.resize(n,1);
        this->component=n;
        for(int i=0;i<n;i++) parent[i]=i;
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
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n=isConnected.size();
        dsu d(n);
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(isConnected[i][j]==1 && i!=j)
                d.union_m(i,j);
            }
        }
        return d.component;
    }
};