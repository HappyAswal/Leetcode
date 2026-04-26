class Solution {
public:
    bool flag=false;
    int dx[4]={0,0,-1,1};
    int dy[4]={1,-1,0,0};
    vector<vector<bool>>vis;
    int n,m;
    void dfs(int i,int j,vector<vector<char>>& grid,int pi,int pj){
        vis[i][j]=true;
        for(int k=0;k<4;k++){
            int ni=i+dx[k];
            int nj=j+dy[k];
            if(ni>=0 && nj>=0 && ni<n && nj<m && grid[ni][nj]==grid[i][j]){
                if(!vis[ni][nj]) dfs(ni,nj,grid,i,j);
                else if(ni!=pi || nj!=pj && vis[ni][nj]) flag=true;
            }
        }
    }
    bool containsCycle(vector<vector<char>>& grid) {
        n=grid.size(),m=grid[0].size();
        vis.assign(n,vector<bool>(m,false));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!vis[i][j]){
                    dfs(i,j,grid,-1,-1);
                }
            }
        }
        return flag;
    }
};