class Solution {
public:
    int mostFrequentEven(vector<int>& nums) {
        unordered_map<int,int>freq;
        for(int x:nums){
            if(x%2==0) freq[x]++;
        }
        vector<int>ss;
        int lf=0;
        for(auto x:freq){
            lf=max(lf,x.second);
        }
        for(auto x:freq){
            if(x.second==lf) ss.push_back(x.first);
        }
        if(ss.empty()) return -1;
        int ans=*min_element(ss.begin(),ss.end());
        return ans;
    }
};