class Solution {
public:
    int digitsum(int x){
        int sum=0;
        while(x>0){
            int digit=x%10;
            sum+=digit;
            x/=10;
        }
        return sum;
    }
    int smallestIndex(vector<int>& nums) {
        for(int i=0;i<nums.size();i++){
            int x=digitsum(nums[i]);
            if(x==i) return x;
        }
        return -1;
    }
};