class Solution {
public:
    vector<vector<int>> dp;
    int pl(int i, int j, string& s){
        if(i>j) return 0;
        if(i==j) return 1;
        if(dp[i][j]!=-1) return dp[i][j];
        if(s[i]==s[j]) return dp[i][j]=2+pl(i+1,j-1,s);
        else return dp[i][j]=max(pl(i+1,j,s),pl(i,j-1,s));
        
    }
    int longestPalindromeSubseq(string s) {
        int i=0,j=s.size()-1;
        int n=s.size();
        dp.assign(n,vector<int>(n,-1));
        return pl(i,j,s);
    }
};