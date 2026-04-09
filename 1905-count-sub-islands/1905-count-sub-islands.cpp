class Solution {
public:
    int count=0;
    vector<vector<bool>>vis;
    int dx[4]={0,0,-1,1};
    int dy[4]={1,-1,0,0};
    int n,m;
    bool part;
    void dfs(int i,int j,vector<vector<int>>& grid1,vector<vector<int>>& grid2){
        vis[i][j]=true;
        if(grid1[i][j]==0) part=false;
        for(int k=0;k<4;k++){
            int ni=i+dx[k];
            int nj=j+dy[k];
            if(ni>=0 && nj>=0 && ni<n && nj<m && grid2[ni][nj]==1 && !vis[ni][nj]){
                dfs(ni,nj,grid1,grid2);
            }
        }
    }
    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        n=grid1.size(),m=grid1[0].size();
        vis.assign(n,vector<bool>(m,false));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!vis[i][j] && grid2[i][j]==1){
                    part=true;
                    dfs(i,j,grid1,grid2);
                    if(part)count++;
                }
            }
        }
        return count;
    }
};