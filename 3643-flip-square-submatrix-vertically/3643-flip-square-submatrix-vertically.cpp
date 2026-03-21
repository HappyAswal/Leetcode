class Solution {
public:
    vector<vector<int>> reverseSubmatrix(vector<vector<int>>& grid, int x, int y, int k) {
        int endrow=x+k-1;
        int endcol=y+k-1;
        for(int i=x;i<=endrow;i++){
            for(int j=y;j<=endcol;j++){
                swap(grid[endrow][j],grid[i][j]);
            }
            endrow--;
        }
        return grid;
    }
};