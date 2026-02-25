class dsu {
public:
    vector<int> parent,size;
    dsu(int n) {
        parent.resize(n);
        size.resize(n, 1);
        for(int i=0;i<n;i++) parent[i]=i;
    }
    int find(int x) {
        if(parent[x]==x) return x;
        return parent[x]=find(parent[x]);
    }
    void union_m(int a,int b) {
        int pa=find(a);
        int pb=find(b);
        if (pa==pb) return;
        if(size[pa]>=size[pb]){
            parent[pb]=pa;
            size[pa]+=size[pb];
        }else{
            parent[pa]=pb;
            size[pb]+=size[pa];
        }
    }
};
class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        unordered_map<string,int>mp;
        int n=accounts.size();
        dsu d(n);
        for(int i=0;i<n;i++){
            for(int j=1;j<accounts[i].size();j++){
                string e=accounts[i][j];
                if(mp.count(e)) d.union_m(i,mp[e]);
                else mp[e]=i;
            }
        }
        //now traverse in parent and check the mails mapped to index
        //then map that email in dd[parent] push making ans
        unordered_map<int,vector<string>>dodo;
        for(auto&p:mp){
            string mail=p.first;
            int indx=p.second;
            int parent=d.find(indx);
            dodo[parent].push_back(mail);
        }
        vector<vector<string>>ans;
        for(auto&x:dodo){
            int parent=x.first;
            vector<string>&mails=x.second;
            sort(mails.begin(),mails.end());
            vector<string>temp;
            temp.push_back(accounts[parent][0]);
            temp.insert(temp.end(),mails.begin(),mails.end());
            ans.push_back(temp);
        }
        return ans;
    }
};