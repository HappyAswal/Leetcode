class Solution {
public:
    bool check(vector<int>&piles,int mid,int h){
        long long hours=0;
        for(int i=0;i<piles.size();i++){
            hours+=(int)ceil((double)piles[i]/mid);
        }
        return hours<=h;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int start=1;
        int end=*max_element(piles.begin(),piles.end());
        int ans=0;
        while(start<=end){
            int mid=start+(end-start)/2;
            if(check(piles,mid,h)){
                ans=mid;
                end=mid-1;
            }else start=mid+1;
        }
        return ans;
    }
};