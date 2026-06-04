class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int n=nums.size();
        vector<int>freq(n+2,0);
        for(int x:nums){
            freq[x]++;
        }
        for(int i=0;i<freq.size();i++){
            if(freq[i]>1){
                return i;
            }
        }
        return -1;

    }
};