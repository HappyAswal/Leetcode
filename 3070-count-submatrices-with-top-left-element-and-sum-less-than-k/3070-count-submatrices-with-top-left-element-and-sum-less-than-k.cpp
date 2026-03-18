class Solution {
public:
    vector<vector<int>>precom;
    int n,m;
    void pre(vector<vector<int>>& grid){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                precom[i][j]=grid[i-1][j-1]+precom[i-1][j]+precom[i][j-1]-precom[i-1][j-1];
            }
        }
    }
    int countSubmatrices(vector<vector<int>>& grid, int k) {
        n=grid.size();
        m=grid[0].size();
        precom.assign(n+1,vector<int>(m+1,0));
        pre(grid);
        int ans=0;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                //find the count
                if(precom[i][j]<=k) ans++;
            }
        }
        return ans;
    }
};