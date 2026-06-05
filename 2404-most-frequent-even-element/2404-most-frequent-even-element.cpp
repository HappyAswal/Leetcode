class Solution {
public:
    int mostFrequentEven(vector<int>& nums) {
        unordered_map<int,int>freq;
        for(int x:nums){
            if(x%2==0) freq[x]++;
        }
        int mf=0;
        int ans=-1;
        for(auto [x,f]:freq){
            if(f>mf){
                ans=x;
                mf=f;
            }else if(f==mf){
                ans=min(ans,x);
            }
        }
        return ans;
    }
};