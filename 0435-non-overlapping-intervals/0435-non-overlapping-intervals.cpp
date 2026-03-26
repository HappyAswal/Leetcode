class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end(),[](auto& a,auto& b){
            return a[1]<b[1];
        });
        int s=intervals[0][0];
        int e=intervals[0][1];
        int result=0;
        for(int i=1;i<intervals.size();i++){
            int ns=intervals[i][0];
            int ne=intervals[i][1];
            if(s==ns || ns<e) result++;
            else s=ns,e=ne;
        }
        return result;
    }
};