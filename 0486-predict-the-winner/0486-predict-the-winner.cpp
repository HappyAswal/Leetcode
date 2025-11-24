class Solution {
public:

    int solve(int i,int j, vector<int>& arr){
        if(i==j) return arr[i];
        int left = arr[i] - solve(i+1,j,arr);
        int right = arr[j] - solve(i,j-1,arr);
        return max(left,right);

    }
    bool predictTheWinner(vector<int>& nums) {
        int n = nums.size();
        int t = solve(0,n-1,nums);
        return t>=0 ? true : false ;
    }
};