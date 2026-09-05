class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int n=nums.size();
        //find min for each i
        vector<int>mini(n);
        int minii=nums[n-1];
        for(int i=nums.size()-1;i>=0;i--){
            minii=min(minii,nums[i]);
            mini[i]=minii;
        }
        //keep updating maximum
        int maxi=nums[0];
        for(int i=0;i<n;i++){
            maxi=max(maxi,nums[i]);
            if(maxi-mini[i]<=k) return i;
        }
        return -1;
    }
};