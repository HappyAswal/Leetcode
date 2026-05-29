class Solution {
public:
    int convert(int n){
        int nm=0;
        while(n>9){
            int d=n%10;
            nm+=d;
            n=n/10;
        }
        nm+=n;
        return nm;
    }
    int minElement(vector<int>& nums) {
        vector<int>n_nums;
        for(int x:nums){
            int nx=convert(x);
            n_nums.push_back(nx);
        }
        int ans=*min_element(n_nums.begin(),n_nums.end());
        return ans;
    }
};