class Solution {
public:
    int minimumAverageDifference(vector<int>& nums) {
        int n=nums.size();
        vector<long long>prefix(n);
        prefix[0]=nums[0];
        for(int i=1;i<n;i++){
            prefix[i]=prefix[i-1]+nums[i];
        }
        int index=0;
        long long ans=LLONG_MAX;

        for(int i=0;i<n;i++){
            long long ls,rs;
            ls=prefix[i]/(i+1);
            if(i==n-1){
                rs=0;
            }else{
                rs=(prefix[n-1]-prefix[i])/(n-i-1);
            }
            long long diff=abs(ls-rs);
            if(diff<ans){
                index=i;
                ans=diff;
            }
        }
        return index;
    }
};