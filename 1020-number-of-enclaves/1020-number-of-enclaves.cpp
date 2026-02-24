class Solution {
public:
    int n,m,component;
    bool touched_boundary;
    void dfs(int i,int j,vector<vector<int>>& grid,vector<vector<bool>>&vis){
        vis[i][j]=true;
        component++;
        int dx[4]={-1,1,0,0};
        int dy[4]={0,0,1,-1};
        if(i==0 || j==0 || i==n-1 || j==m-1) touched_boundary=true;
        for(int k=0;k<4;k++){
            int ni=i+dx[k];
            int nj=j+dy[k];
            if(ni>=0 && nj>=0 && ni<n && nj<m && grid[ni][nj]==1 && !vis[ni][nj]){
                dfs(ni,nj,grid,vis);
            }
        }
    }
    int numEnclaves(vector<vector<int>>& grid) {
        n=grid.size();
        m=grid[0].size();
        int land=0;
        vector<vector<bool>>vis(n,vector<bool>(m,false));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1 && !vis[i][j]){
                    component=0;
                    touched_boundary=false;
                    dfs(i,j,grid,vis);
                    if(touched_boundary==false) land+=component;
                }
            }
        }
        return land;
    }
};