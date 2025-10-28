class Solution {
public:
    // i<j<k
    //nums[i]<nums[k]<nums[j]
    bool find132pattern(vector<int>& nums) {
        stack<int> st;
        int numsk =INT_MIN;
        for(int i=nums.size()-1;i>=0;i--){
            if(nums[i]<numsk) return true;
            while(!st.empty() && st.top()<nums[i]){
                numsk=st.top();
                st.pop();
            }
            st.push(nums[i]);
        }
        return false;
    }
};