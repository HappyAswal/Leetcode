class Solution {
public:
    int dx[4]={0,0,-1,1};
    int dy[4]={1,-1,0,0};
    int n,m;
    vector<vector<bool>>vis;
    int src_color;
    int f_color;
    void dfs(int i,int j,vector<vector<int>>& image){
        image[i][j]=f_color;
        for(int k=0;k<4;k++){
            int ni=i+dx[k];
            int nj=j+dy[k];
            if(ni>=0 && nj>=0 && ni<n && nj<m && image[ni][nj]==src_color){
                dfs(ni,nj,image);
            }
        }
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        n=image.size(),m=image[0].size();
        src_color=image[sr][sc];
        f_color=color;
        if(src_color==f_color) return image; 
        dfs(sr,sc,image);
        return image;
    }
};