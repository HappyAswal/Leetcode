class Solution {
public:
    vector<vector<int>>dp;
    int solve(vector<int>&cuts,int l, int r){
        if(r-l<2) return 0; //atleast 2 len req to make a cut 0-1-2
        if(dp[l][r]!=-1) return dp[l][r];
        int res=INT_MAX;
        for(int idx=l+1;idx<=r-1;idx++){
            int cost=(cuts[r]-cuts[l])+solve(cuts,l,idx)+solve(cuts,idx,r);
            res=min(res,cost);
        }
        return dp[l][r]=res;
    }
    int minCost(int n, vector<int>& cuts) {
        sort(cuts.begin(),cuts.end());
        cuts.insert(cuts.begin(),0); //0 starting of stick
        cuts.push_back(n); //n ending of stick
        //length of stick = cuts[r]-cuts[l];
        int m=cuts.size();
        dp.assign(m,vector<int>(m,-1));
        return solve(cuts,0,cuts.size()-1);

    }
};