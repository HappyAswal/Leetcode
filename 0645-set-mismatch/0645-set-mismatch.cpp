class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        int n=nums.size();
        int freq[10001]={0};
        for(int x:nums) freq[x]++;
        int missing=-1;
        int repeat=-1;
        for(int i=1;i<=n;i++){
            if(freq[i]==2) repeat=i;
            if(freq[i]==0) missing=i;

        }
        return {repeat,missing};
    }
};