class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int n=numbers.size();
        int a=0,b=n-1;
        while(a<b){
            int sum=numbers[a]+numbers[b];
            if(sum==target) return {a+1,b+1};
            if(sum>target) b--;
            else a++;
        }
        return {-1,-1};
    }
};