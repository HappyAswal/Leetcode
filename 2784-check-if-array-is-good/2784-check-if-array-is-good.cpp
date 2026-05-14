class Solution {
public:
    bool isGood(vector<int>& nums) {
        int n=*max_element(nums.begin(),nums.end());
        int freq[201]={0};
        for(int x:nums){
            freq[x]++;
        }
        for(int i=1;i<n;i++){
            if(freq[i]==0) return false;
            if(freq[i]>1) return false;
        }
        return freq[n]==2;
    }
};