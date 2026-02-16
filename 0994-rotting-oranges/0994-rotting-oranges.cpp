class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int dx[4]={-1,1,0,0};
        int dy[4]={0,0,1,-1};
        int n=grid.size(),m=grid[0].size();
        int time=0;
        vector<vector<bool>>vis(n,vector<bool>(m,false));
        queue<pair<pair<int,int>,int>>q;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==2){
                    q.push({{i,j},0});
                    vis[i][j]=true;
                }
            }
        }
        while(!q.empty()){
            int u=q.front().first.first;
            int v=q.front().first.second;
            int t=q.front().second;
            time=max(time,t);
            q.pop();
            for(int k=0;k<4;k++){
                int nx=u+dx[k];
                int ny=v+dy[k];
                if(nx>=0 && ny>=0 && nx<n && ny<m && !vis[nx][ny] && grid[nx][ny]==1){
                    vis[nx][ny]=true;
                    grid[nx][ny]=2;
                    q.push({{nx,ny},t+1});
                }
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1) return -1;
            }
        }
        return time;
    }
};