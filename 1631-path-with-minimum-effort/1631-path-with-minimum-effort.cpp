class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& grid) {
        int n=grid.size();
        using p=pair<int, pair<int,int>>;
        vector<vector<int>> dist(n, vector<int>(n, INT_MAX));
        priority_queue<p,vector<p>,greater<p>>pq;
        int dx[4]={1,-1,0,0};
        int dy[4]={0,0,1,-1};
        dist[0][0]=0;
        pq.push({0,{0,0}});

        while(!pq.empty()){
            auto[effort,cell]=pq.top();
            auto[i,j]=cell;
            pq.pop();
            if(i==n-1 && j==n-1) return effort;
            for(int k=0;k<4;k++){
                int ni=i+dx[k];
                int nj=j+dy[k];
                if(ni>=0 && nj>=0 && ni<n && nj<n){
                    int new_effort=max(effort,abs(grid[ni][nj]-grid[i][j]));
                    if(new_effort<dist[ni][nj]){
                        dist[ni][nj]=new_effort;
                        pq.push({dist[ni][nj],{ni,nj}});
                    }
                }
            }
        }
        return 0;
    }
};