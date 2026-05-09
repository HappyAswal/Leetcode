class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        int freq[101]={0};
        for(int x:nums){
            freq[x]++;
        }
        int mxf=*max_element(freq,freq+101);
        int ans=0;
        for(int f:freq){
            if(f==mxf){
                ans+=f;
            }
        }
        return ans;
    }
};