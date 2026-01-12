class Solution {
public:
    int dp[11][2][11];
    int numberofones(int idx,bool res,int cnt,string& s){
        if(idx==s.size()) return cnt;
        if(dp[idx][res][cnt]!=-1) return dp[idx][res][cnt];
        int upper_bound=(res==1)?s[idx]-'0':9;
        int result=0;
        for(int digit=0;digit<=upper_bound;digit++){
            result=result+numberofones(idx+1,(res&&digit==upper_bound),cnt+(digit==1),s);
        }
        return dp[idx][res][cnt]=result;
    }
    int countDigitOne(int n) {

        string s= to_string(n);
        memset(dp, -1, sizeof(dp));
        return numberofones(0,true,0,s);
    }
};