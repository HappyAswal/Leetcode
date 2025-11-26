class Solution {
public:
    void solve(int s ,vector<int>& cookies, vector<int>& temp, int k ,int& ans){
        int n=cookies.size();
        if(s==n){
            int maxi=INT_MIN;
            for(int i=0;i<k;i++){
                maxi=max(maxi,temp[i]);
            }
            ans=min(ans,maxi);
            return;
        }

        for(int i=0;i<k;i++){
            temp[i] += cookies[s]; //take
            solve(s+1,cookies,temp,k,ans);
            temp[i] -=cookies[s];
        }
    }

    int distributeCookies(vector<int>& cookies, int k) {
        int ans = INT_MAX;
        vector<int> temp(k,0);
        solve(0,cookies,temp,k,ans);
        return ans;
    }
};