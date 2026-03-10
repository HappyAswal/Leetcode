class Solution {
public:
    int maxDistance(vector<vector<int>>& grid) {
        int n=grid.size();
        vector<vector<int>>dist(n,vector<int>(n,INT_MAX));
        queue<pair<int,int>>q;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1){
                    q.push({i,j});
                    dist[i][j]=0;
                }
            }
        }
        if(q.empty()||q.size()==n*n) return -1;
        int dx[4]={1,-1,0,0};
        int dy[4]={0,0,-1,1};
        while(!q.empty()){
            auto[i,j]=q.front(); q.pop();
            for(int k=0;k<4;k++){
                int ni=i+dx[k];
                int nj=j+dy[k];
                if(ni>=0 && nj>=0 && ni<n && nj<n){
                    if(grid[ni][nj]==0 && dist[ni][nj]>dist[i][j]+1){
                        dist[ni][nj]=dist[i][j]+1;
                        q.push({ni,nj});
                    }
                }
            }
        }
        int ans=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                ans=max(ans,dist[i][j]);
            }
        }
        return ans;
    }
};