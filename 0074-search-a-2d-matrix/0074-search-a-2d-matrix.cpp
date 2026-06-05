class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        vector<int>arr;
        for(auto x:matrix){
            for(auto y:x){
                arr.push_back(y);
            }
        }

        int low=0;
        int high=arr.size()-1;
        while(low<=high){
            int mid=low+(high-low)/2;
            if(arr[mid]==target) return true;
            else if(arr[mid]>target){
                high=mid-1;
            }else{
                low=mid+1;
            }
        }
        return false;

    }
};