class Solution {
public:
    int dx[4]={0,0,-1,1};
    int dy[4]={1,-1,0,0};
    int src_color;
    int clr;
    void dfs(int i,int j,vector<vector<int>>& image){
        image[i][j]=clr;
        for(int k=0;k<4;k++){
            int ni=i+dx[k];
            int nj=j+dy[k];
            if(ni>=0 && nj>=0 && ni<image.size() && nj<image[0].size() && image[ni][nj]==src_color){
                dfs(ni,nj,image);
            }
        }
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        src_color=image[sr][sc];
        clr=color;
        if(src_color==clr) return image;
        dfs(sr,sc,image);
        return image;
    }
};