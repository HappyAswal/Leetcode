#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int n, m;
    int oC, nC;

    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        n = image.size();
        m = image[0].size();
        oC = image[sr][sc];
        nC = color;
        if (oC == nC) return image;
        dfs(sr, sc, image);
        return image;
    }

    void dfs(int x, int y, vector<vector<int>>& image) {
        if (x < 0 || y < 0 || x >= n || y >= m) return;
        if (image[x][y] != oC) return;
        image[x][y] = nC;
        dfs(x - 1, y, image);
        dfs(x + 1, y, image);
        dfs(x, y - 1, image);
        dfs(x, y + 1, image);
    }
};