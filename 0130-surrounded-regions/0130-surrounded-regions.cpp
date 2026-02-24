class Solution {
public:
    int n,m;
    bool touched_boundary;
    vector<vector<int>>changes;
    void dfs(int i,int j,vector<vector<char>>& grid,vector<vector<bool>>&vis){
        vis[i][j]=true;
        changes.push_back({i,j});
        int dx[4]={-1,1,0,0};
        int dy[4]={0,0,1,-1};
        if(i==0 || j==0 || i==n-1 || j==m-1) touched_boundary=true;
        for(int k=0;k<4;k++){
            int ni=i+dx[k];
            int nj=j+dy[k];
            if(ni>=0 && nj>=0 && ni<n && nj<m && grid[ni][nj]=='O' && !vis[ni][nj]){
                dfs(ni,nj,grid,vis);
            }
        }
    }
    void solve(vector<vector<char>>& grid) {
        n=grid.size();
        m=grid[0].size();
        vector<vector<bool>>vis(n,vector<bool>(m,false));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]=='O' && !vis[i][j]){
                    touched_boundary=false;
                    changes.clear();
                    dfs(i,j,grid,vis);
                    if(touched_boundary==false){
                        for(auto&v:changes){
                            grid[v[0]][v[1]]='X';
                        }
                    }
                    changes.clear();
                }
            }
        }
    }
};