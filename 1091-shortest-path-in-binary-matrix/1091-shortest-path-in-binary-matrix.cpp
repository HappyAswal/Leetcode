
class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n=grid.size();
        if(grid[0][0]==1 || grid[n-1][n-1] ==1) return -1;

        using p = pair<int, pair<int,int>>;
        vector<vector<int>> dist(n, vector<int>(n, INT_MAX));
        priority_queue<p,vector<p>,greater<p>>pq;
        int dx[8]={1,-1,0,0,1,1,-1,-1};
        int dy[8]={0,0,1,-1,1,-1,1,-1};
        pq.push({1,{0,0}});
        dist[0][0]=1;
        while(!pq.empty()){
            auto[d,cell]=pq.top();
            auto[i,j]=cell;
            pq.pop();
            if(i==n-1 && j==n-1) return d;
            if(d>dist[i][j]) continue;
            for(int k=0;k<8;k++){
                int ni=i+dx[k];
                int nj=j+dy[k];
                if(ni>=0 && nj>=0 && ni<n && nj<n && grid[ni][nj]==0){
                    if(dist[ni][nj]>d+1){
                        dist[ni][nj]=d+1;
                        pq.push({dist[ni][nj],{ni,nj}});
                    }
                }
            }
        }
        return -1;
    }
};