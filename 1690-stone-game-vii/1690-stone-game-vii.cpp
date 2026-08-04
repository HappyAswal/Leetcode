class Solution {
public:
    int n;
    vector<int>prefix;
    vector<vector<vector<int>>>dp;
    int sum(int l,int r){
        if(l==0) return prefix[r];
        return prefix[r]-prefix[l-1];
    }
    //0->Alice Turn
    int solve(bool turn,int i,int j,vector<int>&stones){
        if(i==j) return 0;
        if(dp[i][j][turn]!=-1) return dp[i][j][turn];
        if(!turn){
            int r_left=sum(i+1,j)+solve(1,i+1,j,stones);
            int r_right=sum(i,j-1)+solve(1,i,j-1,stones);
            return dp[i][j][turn]=max(r_left,r_right);
        }else{
            int r_left=-sum(i+1,j)+solve(0,i+1,j,stones);
            int r_right=-sum(i,j-1)+solve(0,i,j-1,stones);
            return dp[i][j][turn]=min(r_left,r_right);
        }
    }
    int stoneGameVII(vector<int>& stones) {
        n=stones.size();
        int i=0,j=n-1;
        prefix.assign(n,0);
        prefix[0]=stones[0];
        for(int i=1;i<n;i++){
            prefix[i]=stones[i]+prefix[i-1];
        }
        dp.assign(n,vector<vector<int>>(n,vector<int>(2,-1)));
        return solve(0,i,j,stones);
    }
};