class Solution {
public:
    vector<vector<int>>ans;
    vector<int>dp;
    int solve(int i,string& s){
        if(i==s.size()) return dp[i]=1;
        if(dp[i]!=-1) return dp[i];
        if(s[i]=='0') return dp[i]=0;
        int ith=solve(i+1,s);
        int i_i1th=0;
        if(i+1<s.size()){
            if(s[i]=='1'||(s[i]=='2' && s[i+1]<='6' )){
                i_i1th=solve(i+2,s);
            }
        }
        return dp[i]=ith + i_i1th;
    }
    int numDecodings(string s) {
        int n=s.size();
        dp.assign(101,-1);
        return solve(0,s);
    }   
};