class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        int sn=*min_element(nums.begin(),nums.end());
        int ln=*max_element(nums.begin(),nums.end());
        vector<int>freq(ln+1,0);
        for(int x:nums) freq[x]++;
        vector<int>arr;
        for(int i=sn;i<=ln;i++){
            if(freq[i]<1){arr.push_back(i);}
        }
        return arr;
    }
};