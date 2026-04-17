class Solution {
public:
    vector<vector<bool>>vis;
    int n,m;
    int dx[4]={0,0,-1,1};
    int dy[4]={-1,1,0,0};
    void dfs(int i,int j,vector<vector<int>>&grid,int& count){
        vis[i][j]=true;
        count++;
        for(int k=0;k<4;k++){
            int ni=i+dx[k];
            int nj=j+dy[k];
            if(ni>=0 && nj>=0 && ni<n && nj<m && !vis[ni][nj] && grid[ni][nj]==1){
                dfs(ni,nj,grid,count);
            }
        }  
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        n=grid.size(),m=grid[0].size();
        vis.assign(n,vector<bool>(m,false));
        int area=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1 && !vis[i][j]){
                    int count=0;
                    dfs(i,j,grid,count);
                    area=max(count,area);
                }
            }
        }
        return area;
    }
};