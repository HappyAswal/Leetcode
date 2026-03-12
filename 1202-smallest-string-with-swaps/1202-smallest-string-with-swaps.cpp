class dsu{
    public:
    vector<int>parent;
    int component;
    dsu(int n){
        parent.resize(n);
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
        if(px>py){
            swap(px,py);
        }
        parent[py]=px;
    }
};
class Solution {
public:
    string smallestStringWithSwaps(string s, vector<vector<int>>& pairs) {
        int n=s.size();
        dsu ds(n);
        unordered_map<int,vector<int>>mp;
        for(int i=0;i<pairs.size();i++){
            int x=pairs[i][0];
            int y=pairs[i][1];
            ds.union_m(x,y);
        }
        for(int i=0;i<n;i++){
            mp[ds.find(i)].push_back(i);
        }
        for(auto&x:mp){
            string ts="";
            int index=x.first;
            vector<int>tt=x.second;
            for(int i=0;i<tt.size();i++){
                int id=tt[i];
                ts+=s[id];
            }
            sort(ts.begin(),ts.end());
            for(int i=0;i<tt.size();i++){
                int id=tt[i];
                s[id]=ts[i];
            }
        }
        return s;
    }
};