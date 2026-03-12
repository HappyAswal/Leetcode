class TreeAncestor {
public:
    vector<vector<int>>up;
    TreeAncestor(int n, vector<int>& parent) {
        int col=16;
        up.assign(n,vector<int>(col,-1));
        //1st column fill
        for(int i=0;i<n;i++) up[i][0]=parent[i];
        //table filling
        for(int j=1;j<col;j++){
            for(int i=0;i<n;i++){
                if(up[i][j-1]!=-1) up[i][j]=up[up[i][j-1]][j-1];
            }
        }
    }
    int getKthAncestor(int node, int k) {
        for(int j=0;j<16;j++){
            if(k & (1<<j)){
                node=up[node][j];
                if(node==-1) return node;
            }
        }
        return node;
    }
};

/**
 * Your TreeAncestor object will be instantiated and called as such:
 * TreeAncestor* obj = new TreeAncestor(n, parent);
 * int param_1 = obj->getKthAncestor(node,k);
 */