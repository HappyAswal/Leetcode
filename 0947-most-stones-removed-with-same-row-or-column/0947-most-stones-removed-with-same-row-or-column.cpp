class dsu{
  public:
  vector<int>parent,size;
  int component;
  dsu(int x){
    parent.resize(x);
    size.resize(x,1);
    this->component=x;
    for(int i=0;i<x;i++) parent[i]=i;
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
    }else{
        parent[px]=py;
        size[py]+=size[px];
    }
    component--;
  }
};
class Solution {
public:
    int removeStones(vector<vector<int>>& stones) {
        int n=stones.size();
        dsu ds(n);
        for(int i=0;i<stones.size();i++){
            for(int j=i+1;j<n;j++){ 
                if(stones[i][0]==stones[j][0] || stones[i][1]==stones[j][1]){
                    ds.union_m(i,j);
                }
            }
        }
        return n-ds.component;
    }
};