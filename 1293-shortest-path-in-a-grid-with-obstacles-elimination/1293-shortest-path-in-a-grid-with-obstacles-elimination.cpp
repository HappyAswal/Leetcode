class Solution {
public:
    int shortestPath(vector<vector<int>>& grid, int k) {
        int n=grid.size(),m=grid[0].size();

        int dx[4]={1,-1,0,0};
        int dy[4]={0,0,-1,1};
        queue<tuple<int,int,int,int>>q;
        vector<vector<int>>hurdle(n,vector<int>(m,INT_MAX));
        hurdle[0][0]=0;
        q.push({0,0,0,0});
        while(!q.empty()){
            auto[obs,step,i,j]=q.front();
            q.pop();
            if(obs>k) continue;
            if(i==n-1 && j==m-1) return step;
            for(int p=0;p<4;p++){
                int ni=i+dx[p];
                int nj=j+dy[p];
                if(ni>=0 && nj>=0 && ni<n && nj<m){
                    int nobs=obs+grid[ni][nj];
                    if(nobs<=k && hurdle[ni][nj]>nobs){
                        hurdle[ni][nj]=nobs;
                        q.push({nobs,step+1,ni,nj});
                    }
                }
            }
        }
        return -1;

    }
};