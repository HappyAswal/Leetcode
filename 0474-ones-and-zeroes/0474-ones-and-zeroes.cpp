class Solution {
public:
    vector<vector<vector<int>>>dp;
    int solve(int i,int cm,int cn,vector<string>& strs, int m, int n){
        if(cm>m || cn>n) return 0;
        if(i>=strs.size()) return 0;
        if(dp[i][cm][cn]!=-1) return dp[i][cm][cn];
        int mm=0;
        int nn=0;
        for(char&c:strs[i]){
            if(c=='0') mm++;
            if(c=='1') nn++;
        }
        int p=0;
        if(cm+mm<=m && cn+nn<=n){
            p=1+solve(i+1,cm+mm,cn+nn,strs,m,n);
        }
        int np=solve(i+1,cm,cn,strs,m,n);
        return dp[i][cm][cn]=max(p,np);
    }
    int findMaxForm(vector<string>& strs, int m, int n) {
        dp.assign(strs.size(),vector<vector<int>>(m+1,vector<int>(n+1,-1)));
        return solve(0,0,0,strs,m,n);
    }
};