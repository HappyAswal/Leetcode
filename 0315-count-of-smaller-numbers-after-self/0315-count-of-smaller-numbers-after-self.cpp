class Solution {
public:
    vector<int>count;
    void merge(vector<pair<int,int>>&arr,int low,int mid,int high){
        vector<pair<int,int>>temp;
        //low..mid
        //mid+1..high
        int left=low;
        int right=mid+1;
        int rcount=0;

        while(left<=mid && right<=high){
            if(arr[left].first<=arr[right].first){
                temp.push_back(arr[left]);
                count[arr[left].second]+=rcount;
                left++;
            }
            //right smaller
            else{
                temp.push_back(arr[right]);
                rcount++;
                right++;
            }
        }
        while(left<=mid){
            count[arr[left].second]+=rcount;
            temp.push_back(arr[left]);
            left++;
        }
        while(right<=high){
            temp.push_back(arr[right]);
            right++;
        } 
        for(int i=low;i<=high;i++){
            arr[i]=temp[i-low];
        }
    }
    void mergesort(vector<pair<int,int>>&arr,int low, int high){
        if(low>=high) return;
        int mid= low+(high-low)/2;
        mergesort(arr,low,mid);
        mergesort(arr,mid+1,high);
        merge(arr,low,mid,high);
    }
    vector<int> countSmaller(vector<int>& nums) {
        int n=nums.size();
        vector<pair<int,int>>arr;
        count.assign(n,0);
        //value-index
        for(int i=0;i<n;i++){
            arr.push_back({nums[i],i});
        }
        mergesort(arr,0,n-1);
        return count;
    }
};