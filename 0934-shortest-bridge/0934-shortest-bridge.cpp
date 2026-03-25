class Solution {
public:
    int dx[4]={-1,1,0,0};
    int dy[4]={0,0,1,-1};
    int n;
    queue<pair<int,int>>q;
    void dfs(int i,int j,vector<vector<int>>&grid,vector<vector<bool>>&vis){
        vis[i][j]=true;
        q.push({i,j});
        for(int k=0;k<4;k++){
            int ni=i+dx[k];
            int nj=j+dy[k];
            if(ni<n && nj<n && ni>=0 && nj>=0 && grid[ni][nj]==1 && !vis[ni][nj]){
                dfs(ni,nj,grid,vis);
            }
        }
    }
    int shortestBridge(vector<vector<int>>& grid) {
        n=grid.size();
        vector<vector<bool>>vis(n,vector<bool>(n,false));
        bool flag=false;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1){
                    dfs(i,j,grid,vis);
                    flag=true;
                    break;
                }
            }
            if(flag)break;
        }
        //bfs
        int lvl=0;
        while(!q.empty()){
            int size=q.size();
            while(size--){
                auto x=q.front(); q.pop();
                int i=x.first,j=x.second;
                for(int k=0;k<4;k++){
                    int ni=i+dx[k];
                    int nj=j+dy[k];
                    if(ni<n && nj<n && ni>=0 && nj>=0 && !vis[ni][nj]){
                        if(grid[ni][nj]==1) return lvl;
                        else{
                            vis[ni][nj]=true;
                            q.push({ni,nj});
                        }
                        
                    }
                }
            }
            lvl++;
        }
        return -1;
    }
};