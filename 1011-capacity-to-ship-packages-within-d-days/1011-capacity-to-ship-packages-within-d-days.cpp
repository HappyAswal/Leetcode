class Solution {
public:
    bool ispossible(int mid,int d,int n,vector<int>& weights){
        int days=1;
        int total=0;
        for(int i=0;i<n;i++){
            if(weights[i]>mid) return false;
            if(total+weights[i]<=mid) total+=weights[i];
            else{
                days++;
                total=weights[i];
            }
        }
        return days<=d;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int sum=accumulate(weights.begin(),weights.end(),0);
        int n=weights.size();
        int start=1,end=sum;
        int cap=sum;
        while(start<=end){
            int mid=start+(end-start)/2;
            if(ispossible(mid,days,n,weights)){
                cap=mid;
                end=mid-1;
            }
            else start=mid+1;
        }
        return cap;
    }
};