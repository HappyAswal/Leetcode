class Solution {
public:
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        int si=entrance[0],sj=entrance[1];
        int n=maze.size(),m=maze[0].size();
        vector<vector<int>>dist(n,vector<int>(m,INT_MAX));
        queue<pair<int,int>>q;
        q.push({si,sj});
        dist[si][sj]=0;
        int dx[4]={-1,1,0,0};
        int dy[4]={0,0,-1,1};
        while(!q.empty()){
            auto[i,j]=q.front(); q.pop();
            for(int k=0;k<4;k++){
                int ni=i+dx[k];
                int nj=j+dy[k];
                if(ni>=0 && nj>=0 && ni<n && nj<m){
                    if(maze[ni][nj]=='.' && dist[ni][nj]>dist[i][j]+1){
                        dist[ni][nj]=dist[i][j]+1;
                        q.push({ni,nj});
                    }
                }
            }
        }
        int ans=INT_MAX;
        for(int i=0;i<m;i++){
            if(!(0==si && i==sj)) ans=min(ans,dist[0][i]);
            if(!(n-1==si && i==sj)) ans=min(ans,dist[n-1][i]);
        }
        for(int j=0;j<n;j++){
            if(!(j==si && 0==sj)) ans=min(ans,dist[j][0]);
            if(!(j==si && m-1==sj)) ans=min(ans,dist[j][m-1]);
        }
        return ans==INT_MAX?-1:ans;
    }
};