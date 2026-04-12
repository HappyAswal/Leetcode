class Solution {
public:
    int count;
    void fxn(int x,int digit){
        while(x>0){
            int d=x%10;
            if(d==digit) count++;
            x/=10;
        }
    }
    int countDigitOccurrences(vector<int>& nums, int digit) {
        count=0;
        for(int i=0;i<nums.size();i++){
            fxn(nums[i],digit);
        }
        return count;
    }
};