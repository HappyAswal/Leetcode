class Solution {
public:
    int n,m;
    vector<vector<int>>dp;
    int fxn(int i,int j,string& w1,string& w2){
        if(i==n) return m-j;
        if(j==m) return n-i;
        if(dp[i][j]!=-1) return dp[i][j];
        if(w1[i]==w2[j]) return fxn(i+1,j+1,w1,w2);

        int ins=1+fxn(i,j+1,w1,w2);
        int del=1+fxn(i+1,j,w1,w2);
        int rep=1+fxn(i+1,j+1,w1,w2);
        return dp[i][j]=min({ins,del,rep});
    }
    int minDistance(string word1, string word2) {
        n=word1.size(),m=word2.size();
        dp.assign(n+1,vector<int>(m+1,-1));
        return fxn(0,0,word1,word2);
    }
};