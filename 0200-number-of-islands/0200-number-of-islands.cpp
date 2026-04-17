class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int n=grid.size(),m=grid[0].size();
        vector<vector<bool>>vis(n,vector<bool>(m,false));
        int dx[4]={1,-1,0,0};
        int dy[4]={0,0,-1,1};
        int island=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]=='1' && !vis[i][j]){
                    //do bfs
                    queue<pair<int,int>>q;
                    q.push({i,j});
                    while(!q.empty()){
                        auto[x,y]=q.front(); q.pop();
                        vis[x][y]=true;
                        for(int k=0;k<4;k++){
                            int ni=x+dx[k];
                            int nj=y+dy[k];
                            if(ni>=0 && nj>=0 && ni<n && nj<m && !vis[ni][nj] && grid[ni][nj]=='1'){
                                q.push({ni,nj});
                            }
                        }
                    }
                    island++;
                }
            }
        }
        return island;

    }
};