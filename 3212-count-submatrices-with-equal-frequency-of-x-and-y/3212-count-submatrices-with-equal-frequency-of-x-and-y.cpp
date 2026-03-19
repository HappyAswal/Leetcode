class Solution {
public:
    int numberOfSubmatrices(vector<vector<char>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        int count=0;
        vector<int>px(m,0);
        vector<int>py(m,0);

        for(int i=0;i<n;i++){
            int cx=0,cy=0;
            for(int j=0;j<m;j++){
                if(grid[i][j]=='X') cx++;
                else if(grid[i][j]=='Y') cy++;
                px[j]+=cx;
                py[j]+=cy;
                if(px[j]==py[j] && px[j]>0) count++;
            }
        }
        return count;
    }
};