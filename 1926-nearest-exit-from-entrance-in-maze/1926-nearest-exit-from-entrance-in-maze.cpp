class Solution {
public:
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        int si=entrance[0],sj=entrance[1];
        int n=maze.size(),m=maze[0].size();
        queue<pair<int,int>>q;
        vector<vector<bool>>vis(n,vector<bool>(m,false));
        q.push({si,sj});
        vis[si][sj]=true;
        int steps=0;
        int dx[4]={-1,1,0,0};
        int dy[4]={0,0,1,-1};
        while(!q.empty()){
            int z=q.size();
            while(z--){
                auto[i,j]=q.front(); q.pop();
                if((i!=si || j!=sj) && (i==0 || j==0 || i==n-1 || j==m-1)) return steps; 
                for(int k=0;k<4;k++){
                    int ni=i+dx[k];
                    int nj=j+dy[k];
                    if(ni>=0 && nj>=0 && ni<n && nj<m && !vis[ni][nj] && maze[ni][nj]=='.'){
                        vis[ni][nj]=true;
                        q.push({ni,nj});
                    }
                }
            }
            steps++;
        }
        return -1;
    }
};