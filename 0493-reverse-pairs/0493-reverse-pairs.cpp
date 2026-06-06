class Solution {
public:
    long long count=0;
    void countpairs(int low,int mid,int high,vector<int>&nums){
        int right=mid+1;
        for(int i=low;i<=mid;i++){
            while(right<=high && (long long)nums[i]>2LL*nums[right]){
                right++;
            }
            count+=right-(mid+1);
        }
    }
    void merge(int low,int mid,int high,vector<int>&nums){
        // int right=mid+1;
        // for(int i=low;i<=mid;i++){
        //     while(right<=high && nums[i]>2*nums[right]){
        //         right++;
        //     }
        //     count+=right-(mid+1);
        // }
        countpairs(low,mid,high,nums);
        vector<int>temp;
        int left=low;
        int right=mid+1;
        
        while(left<=mid && right<=high){
            if(nums[left]<=nums[right]){
                temp.push_back(nums[left]);
                left++;
            }else{
                temp.push_back(nums[right]);
                right++;
            }
        }
        while(left<=mid){
            temp.push_back(nums[left]);
            left++;
        }
        while(right<=high){
            temp.push_back(nums[right]);
            right++;
        }
        for(int i=low;i<=high;i++){
            nums[i]=temp[i-low];
        }
    }
    void mergesort(int low,int high,vector<int>&nums){
        if(low>=high) return;
        int mid=low+(high-low)/2;
        mergesort(low,mid,nums);
        mergesort(mid+1,high,nums);
        merge(low,mid,high,nums);
    }
    int reversePairs(vector<int>& nums) {
        mergesort(0,nums.size()-1,nums);
        return (int)count;
    }
};