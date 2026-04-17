class Solution {
public:
    vector<vector<bool>>vis;
    void dfs(int i,int j,vector<vector<char>>& grid){
        if(i<0 || j<0 || i>=grid.size() || j>=grid[0].size() || grid[i][j]=='0' || vis[i][j]) return;
        vis[i][j]=true;
        dfs(i+1,j,grid);
        dfs(i,j+1,grid);
        dfs(i-1,j,grid);
        dfs(i,j-1,grid);
    }
    int numIslands(vector<vector<char>>& grid){
        int n=grid.size(),m=grid[0].size();
        vis.assign(n,vector<bool>(m,false));
        int island=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]=='1' && !vis[i][j]){
                    dfs(i,j,grid);
                    island++;
                }
            }
        }
        return island;
    }
};