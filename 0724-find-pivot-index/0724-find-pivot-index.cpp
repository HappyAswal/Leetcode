class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int n=nums.size();
        vector<int>prefixl(n);
        vector<int>prefixr(n);
        prefixl[0]=nums[0];
        prefixr[n-1]=nums[n-1];
        for(int i=1;i<n;i++) prefixl[i]=prefixl[i-1]+nums[i];
        for(int i=n-2;i>=0;i--) prefixr[i]=prefixr[i+1]+nums[i];

        for(int i=0;i<n;i++){
            if(prefixl[i]==prefixr[i]){
                return i;
            }
        }
        return -1;
    }
};