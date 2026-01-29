class Solution {
public:
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        sort(boxTypes.begin(),boxTypes.end(),[](auto &a, auto &b){
            return a[1] > b[1];
        });
        int ans=0;

        for(auto& box:boxTypes){
            int count=box[0];
            int units=box[1];
            if(truckSize==0) break;
            int take=min(count,truckSize);
            ans+=take*units;
            truckSize-=take;
        }
        return ans;
    }
};