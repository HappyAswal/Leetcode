class Solution {
public:
    string shortestCommonSupersequence(string str1, string str2) {
        vector<vector<int>>dp(str1.size()+1,vector<int>(str2.size()+1,0));
        for(int i=1;i<=str1.size();i++){
            for(int j=1;j<=str2.size();j++){
                if(str1[i-1]==str2[j-1]) dp[i][j]=1+dp[i-1][j-1];
                else dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
            }
        }
        
        string lcs ="";
        int i=str1.size(),j=str2.size();
        while(i>0 && j>0){
            if(str1[i-1]==str2[j-1]){
                lcs.push_back(str1[i-1]);
                i--;
                j--;
            }else{
                if(dp[i-1][j]>dp[i][j-1]) i--;
                else j--;
            }
        }
        reverse(lcs.begin(),lcs.end());

        string ans = "";
        i = j = 0;
        for(char c : lcs){
            while(str1[i] != c) ans.push_back(str1[i++]);
            while(str2[j] != c) ans.push_back(str2[j++]);
            ans.push_back(c);
            i++; 
            j++;
        }
        ans += str1.substr(i);
        ans += str2.substr(j);
        return ans;
    }
};