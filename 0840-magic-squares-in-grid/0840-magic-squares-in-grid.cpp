class Solution {
public:
    bool isms(vector<vector<int>>&ms){
        int rs1=0, rs2=0, rs3=0;
        int cs1=0, cs2=0, cs3=0;
        int ds1=0, ds2=0;

        // check numbers 1..9 distinct
        vector<bool> seen(10,false);
        for(int i=0;i<3;i++){
            for(int j=0;j<3;j++){
                int x = ms[i][j];
                if(x < 1 || x > 9 || seen[x]) return false;
                seen[x] = true;
            }
        }
        for(int i=0;i<3;i++) rs1+=ms[0][i];
        for(int i=0;i<3;i++) rs2+=ms[1][i];
        for(int i=0;i<3;i++) rs3+=ms[2][i];

        for(int i=0;i<3;i++) cs1+=ms[i][0];
        for(int i=0;i<3;i++) cs2+=ms[i][1];
        for(int i=0;i<3;i++) cs3+=ms[i][2];

        ds1=ms[0][0]+ms[1][1]+ms[2][2];
        ds2=ms[0][2]+ms[1][1]+ms[2][0];
        if(ds1 != ds2 || rs1!=rs2 || rs1!=rs3 || rs2!=rs3 || cs1!=cs2 || cs1!=cs3 || cs2!=cs3) return false;
        else return true;
    }
    int numMagicSquaresInside(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        int cnt = 0;

        for(int i=0;i+2<n;i++){
            for(int j=0;j+2<m;j++){
                vector<vector<int>> ms(3, vector<int>(3));
                for(int r=0;r<3;r++){
                    for(int c=0;c<3;c++){
                        ms[r][c] = grid[i+r][j+c];
                    }
                }
                if(isms(ms)) cnt++;
            }
        }
        return cnt;
    }
};