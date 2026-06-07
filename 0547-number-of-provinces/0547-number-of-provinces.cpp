class DSU{
    public:
    vector<int>parent,size;
    int components;
    DSU(int n){
        parent.resize(n);
        size.resize(n,1);
        for(int i=0;i<n;i++) parent[i]=i;
        components=n;
    }
    int find(int x){
        if(parent[x]==x) return x;
        return parent[x]=find(parent[x]);
    }
    void d_union(int x,int y){
        int px=find(x);
        int py=find(y);
        if(px==py) return;
        if(size[px]>=size[py]){
            size[px]+=size[py];
            parent[py]=px;
        }else{
            size[py]+=size[px];
            parent[px]=py;
        }
        components--;
    }
    
};
class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n=isConnected.size();
        DSU d(n);
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(isConnected[i][j]==1){
                    d.d_union(i,j);
                }
            }
        }
        return d.components;
    }
};