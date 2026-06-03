class Solution {
public:
    void convertzero(int i,int j,vector<vector<int>>&matrix){
        for(int x=0;x<matrix[0].size();x++){
            matrix[i][x]=0;
        }
        for(int y=0;y<matrix.size();y++){
            matrix[y][j]=0;
        }

    }
    void setZeroes(vector<vector<int>>& matrix) {
        vector<pair<int,int>>zeros;
        for(int i=0;i<matrix.size();i++){
            for(int j=0;j<matrix[0].size();j++){
                if(matrix[i][j]==0){
                    zeros.push_back({i,j});
                }
            }
        }
        for(auto x:zeros){
            convertzero(x.first,x.second,matrix);
        }
    }
};