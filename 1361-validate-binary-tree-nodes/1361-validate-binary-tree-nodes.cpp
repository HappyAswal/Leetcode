class Solution {
public:
    bool validateBinaryTreeNodes(int n, vector<int>& leftChild, vector<int>& rightChild) {
        vector<vector<int>>adj(n);
        unordered_map<int,int>cp;//child_parent
        for(int i=0;i<n;i++){
            int node=i;
            int lc=leftChild[i];
            int rc=rightChild[i];
            if(lc!=-1){
                adj[i].push_back(lc);
                if(cp.find(lc)!=cp.end()) return false;
                cp[lc]=node;
            }
            if(rc!=-1){
                adj[i].push_back(rc);
                if(cp.find(rc)!=cp.end()) return false;
                cp[rc]=node;
            }          
        }
        int root=-1;
        for(int i=0;i<n;i++){
            if(cp.find(i)==cp.end()){
                if(root!=-1) return false;
                root=i;
            }
        }
        if(root==-1) return false;
        queue<int>q;
        vector<int>vis(n,false);
        int comp=1;
        q.push(root);
        vis[root]=true;
        while(!q.empty()){
            int src=q.front(); q.pop();
            for(auto&nbr:adj[src]){
                if(!vis[nbr]){
                    vis[nbr]=true;
                    q.push(nbr);
                    comp++;
                }
            }
        }
        return comp==n;
    }
};