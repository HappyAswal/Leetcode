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
    }
};
class Solution {
public:
    bool equationsPossible(vector<string>& equations) {
        int n=equations.size();
        dsu d(26);
        for(int i=0;i<n;i++){
            if(equations[i][1]=='='){
                d.union_m(equations[i][0]-'a',equations[i][3]-'a');
            }
        }
        for(int i=0;i<n;i++){
            if(equations[i][1]=='!'){
                int a=d.find(equations[i][0]-'a');
                int b=d.find(equations[i][3]-'a');
                if(a==b) return false;
            }
        }
        return true;
    }
};