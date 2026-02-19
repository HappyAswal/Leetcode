class Solution {
public:
    int minimumObstacles(vector<vector<int>>& grid) {
        int n=grid.size(),m=grid[0].size();
        vector<vector<int>>obs(n,vector<int>(m,INT_MAX));
        int dx[4]={1,-1,0,0};
        int dy[4]={0,0,-1,1};
        priority_queue<tuple<int,int,int>,vector<tuple<int,int,int>>,greater<tuple<int,int,int>>>pq;
        obs[0][0]=0;
        pq.push({0,0,0});
        while(!pq.empty()){
            auto[o,i,j]=pq.top(); pq.pop();
            if(o>obs[i][j]) continue;
            for(int k=0;k<4;k++){
                int ni=i+dx[k];
                int nj=j+dy[k];
                
                if(ni>=0 && nj>=0 && ni<n && nj<m){
                    if(grid[ni][nj]==1 && obs[ni][nj]>o+1){
                        obs[ni][nj]=o+1;
                        pq.push({o+1,ni,nj});
                    }
                    else if(grid[ni][nj]==0 && obs[ni][nj]>o){
                        obs[ni][nj]=o;
                        pq.push({o,ni,nj});
                    }   
                }
            }
        }
        return obs[n-1][m-1];
    }
};