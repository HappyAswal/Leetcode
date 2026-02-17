class Solution {
public:
    int n;
    void dfs(int i,vector<vector<int>>& isConnected,vector<bool>&vis){
        vis[i]=true;
        for(int j=0;j<n;j++){
            if(isConnected[i][j]==1 && !vis[j]){
                dfs(j,isConnected,vis);
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        n=isConnected.size();
        vector<bool>vis(n+1,false);
        int cc=0;
        for(int i=0;i<n;i++){
            if(!vis[i]){
                dfs(i,isConnected,vis);
                cc++;
            }
        }
        return cc;
    }
};