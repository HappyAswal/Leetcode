class Solution {
public:
    bool solve(int b,int h,vector<int>&piles){
        long long count=0;
        for(int i=0;i<piles.size();i++){
            count+= ceil((double)piles[i]/b);
        }
        return count<=h;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int low=1;
        int high=*max_element(piles.begin(),piles.end());
        int ans=-1;
        while(low<=high){
            int mid=low+(high-low)/2;
            if(solve(mid,h,piles)){
                ans=mid;
                high=mid-1;
            }else low=mid+1;
        }
        return ans;
    }
};