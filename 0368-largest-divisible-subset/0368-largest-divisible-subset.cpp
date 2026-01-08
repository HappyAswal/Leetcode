class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        vector<int>dp(n,1);
        vector<int>parent(n,-1);
        
        for(int i=0;i<n;i++){
            for(int j=0;j<i;j++){
                if(nums[i]%nums[j]==0){
                    if(dp[i]<dp[j]+1){
                        dp[i]=dp[j]+1;
                        parent[i]=j;
                    }
                }
            }
        }
        int m=*max_element(dp.begin(),dp.end());
        int index=-1;
        for(int i=0;i<n;i++){
            if(dp[i]==m){index=i; break;}
        }
        vector<int>result;
        while(index!=-1){
            result.push_back(nums[index]);
            index=parent[index];
        }
        reverse(result.begin(),result.end());
        return result;
    }
};