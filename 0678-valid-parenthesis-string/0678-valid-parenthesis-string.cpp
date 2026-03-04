class Solution {
public:
    vector<vector<int>>dp;
    bool solve(int i, int count,string& s){
        if(count<0) return false;
        if(i==s.size()) return count==0;
        if(dp[i][count]!=-1) return dp[i][count];
        if(s[i]=='(') return dp[i][count]=solve(i+1,count+1,s);
        else if(s[i]==')') return dp[i][count]=solve(i+1,count-1,s);
        else{
            return dp[i][count]=(solve(i+1,count+0,s)||solve(i+1,count-1,s)||solve(i+1,count+1,s));
        }
    }
    bool checkValidString(string s) {
        dp.assign(s.size()+1,vector<int>(s.size()+1,-1));
        return solve(0,0,s);
    }
};