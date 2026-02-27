class Solution {
public:
    vector<vector<vector<int>>>dp;
    bool solve(int i,int j,int w,string& s1, string& s2, string& s3){
        if(w==s3.size()) return dp[i][j][w]=true;
        if(dp[i][j][w]!=-1) return dp[i][j][w];
        bool ps1=false,ps2=false;
        if(i<s1.size() && s3[w]==s1[i]) ps1=solve(i+1,j,w+1,s1,s2,s3);
        if(j<s2.size() && s3[w]==s2[j]) ps2=solve(i,j+1,w+1,s1,s2,s3);
        return dp[i][j][w]=ps1||ps2;
    }
    bool isInterleave(string s1, string s2, string s3) {
        if(s1.size()+s2.size()!=s3.size()) return false;
        dp.assign(s1.size()+1,vector<vector<int>>(s2.size()+1,vector<int>(s3.size()+1,-1)));
        return solve(0,0,0,s1,s2,s3);
    }
};