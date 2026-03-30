class Solution {
public:
    bool ispossible(vector<int>& arr,int m,int k,int mid){
        int c=0;
        int totalb=0;
        for(int i=0;i<arr.size();i++){
            if(arr[i]<=mid){
                c++;
                if(c==k){
                    totalb++;
                    c=0;
                }
            }else c=0;
        }
        return totalb>=m;
    }
    int minDays(vector<int>& bloomDay, int m, int k) {
        int n=bloomDay.size();
        if((long long)m*k>n) return -1;
        int start=*min_element(bloomDay.begin(),bloomDay.end());
        int end=*max_element(bloomDay.begin(),bloomDay.end());
        int mdays=-1;
        while(start<=end){
            int mid=start+(end-start)/2;
            if(ispossible(bloomDay,m,k,mid)){
                mdays=mid;
                end=mid-1;
            }
            else start=mid+1;
        }
        return mdays;

    }
};