class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>>ans;
        sort(intervals.begin(),intervals.end(),[](auto&a,auto&b){
            if(a[0]==b[0]) return a[1]<b[1];
            else return a[0]<b[0];
        });
        vector<int>tempi=intervals[0];
        for(int i=1;i<intervals.size();i++){
            //overlap condition
            if(intervals[i][0]<=tempi[1]){
                tempi[1]=max(tempi[1],intervals[i][1]);
            }
            //outside
            else{
                ans.push_back(tempi);
                tempi=intervals[i];
            }
        }
        ans.push_back(tempi);
        

        return ans;
    }
};