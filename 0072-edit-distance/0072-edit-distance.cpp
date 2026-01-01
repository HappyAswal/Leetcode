class Solution {
public:
    int m,n;
    vector<vector<int>>dp;
    int minop(int i,int j,string& s1,string& s2){
        if(i==m) return n-j; //insert in s1
        if(j==n) return m-i; //delete from s1

        if(dp[i][j]!=-1) return dp[i][j];

        if(s1[i]==s2[j]) return minop(i+1,j+1,s1,s2);
        int ins=1+minop(i,j+1,s1,s2); //j me insert
        int del=1+minop(i+1,j,s1,s2); //i se del to i move
        int rep=1+minop(i+1,j+1,s1,s2);

        return dp[i][j]=min({ins,del,rep});
    }
    int minDistance(string s1, string s2) {
        m=s1.size();
        n=s2.size();
        dp.assign(s1.size()+1,vector<int>(s2.size()+1,-1));
        return minop(0,0,s1,s2);
    }
};