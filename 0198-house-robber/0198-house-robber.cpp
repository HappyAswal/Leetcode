class Solution {
public:
    int rob(vector<int>& arr) {
        vector<int> dp(arr.size(),0);
        int n=arr.size();
        
        if(n == 1) return arr[0];
        if(n == 2) return max(arr[0], arr[1]);
        
        dp[n-1]=arr[n-1];
        dp[n-2]=max(arr[n-1],arr[n-2]);
        
        for(int i=n-3;i>=0;i--){
            dp[i]=max(arr[i]+dp[i+2],dp[i+1]);
        }
        return dp[0];
    }
};