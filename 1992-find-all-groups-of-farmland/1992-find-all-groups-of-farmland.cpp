class Solution {
public:
    vector<vector<int>>ans;
    vector<vector<bool>>vis;
    int n,m;
    int dx[4]={0,0,-1,1};
    int dy[4]={1,-1,0,0};
    
    int si,sj;
    int ei,ej;

    void dfs(int i,int j,vector<vector<int>>& land){
        vis[i][j]=true;
        si=min(si,i);
        sj=min(sj,j);
        ei=max(ei,i);
        ej=max(ej,j);
        for(int k=0;k<4;k++){
            int ni=i+dx[k];
            int nj=j+dy[k];
            if(ni>=0 && nj>=0 && ni<n && nj<m && land[ni][nj]==1  && !vis[ni][nj]){
                dfs(ni,nj,land);
            }
        }
    }
    vector<vector<int>> findFarmland(vector<vector<int>>& land) {
        n=land.size(),m=land[0].size();
        vis.assign(n,vector<bool>(m,false));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!vis[i][j] && land[i][j]==1){
                    si=i,sj=j;
                    ei=i,ej=j;
                    dfs(i,j,land);
                    ans.push_back({si,sj,ei,ej});
                }
            }
        }
        return ans;
    }
};