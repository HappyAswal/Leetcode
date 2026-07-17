class Solution {
public:
    int n;
    vector<bool>vis;
    void dfs(int city,vector<vector<int>>&isConnected){
        vis[city]=true;
        for(int j=0;j<n;j++){
            if(isConnected[city][j] && !vis[j]){
                dfs(j,isConnected);
            }
        }

    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        n=isConnected.size();
        vis.assign(n,false);
        int count=0;
        for(int city=0;city<n;city++){
            if(!vis[city]){
                dfs(city,isConnected);
                count++;
            }
        }
        return count;
    }
};