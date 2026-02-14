class Solution {
public:
    int n,m;
    int dfs(int i,int j,vector<vector<int>>& grid,vector<vector<bool>>&vis){
        vis[i][j]=true;
        int area=1;
        int dx[4] = {-1,0,1,0};
        int dy[4] = {0,-1,0,1};
        for(int k=0;k<4;k++){
            int ni=i+dx[k];
            int nj=j+dy[k];
            if(ni>=0&&nj>=0&&ni<n&&nj<m&&!vis[ni][nj]&&grid[ni][nj]==1)
                area+=dfs(ni,nj,grid,vis);
        }
        return area;
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        n=grid.size();
        m=grid[0].size();
        vector<vector<bool>>vis(n,vector<bool>(m,false));
        int marea=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!vis[i][j] && grid[i][j]==1){
                    int area=dfs(i,j,grid,vis);
                    marea=max(marea,area);
                }
            }
        }
        return marea;
    }
};