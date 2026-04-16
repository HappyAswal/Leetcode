class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n=nums.size();
        deque<int> deq;
        vector<int>ans;
        for(int i=0;i<n;i++){
            while(deq.size()>0 && deq.front()<=i-k){
                deq.pop_front();
            }
            while(deq.size()>0 && nums[i]>=nums[deq.back()]){
                deq.pop_back();
            }
            deq.push_back(i);
            if(i>=k-1){
                ans.push_back(nums[deq.front()]);
            }
        }
        return ans;

    }
};