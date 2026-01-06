class Solution {
public:
    static

    int maxEnvelopes(vector<vector<int>>& envelopes) {
        int n = envelopes.size();
        if(n == 0) return 0;
        sort(envelopes.begin(), envelopes.end(),[](const vector<int>& a, const vector<int>& b){
            if(a[0] == b[0])
                return a[1] > b[1];   // desc height 
            return a[0] < b[0];       // asc width 
        });
        vector<int>temp;
        temp.push_back(envelopes[0][1]);
        for(int i=1;i<n;i++){
            if(envelopes[i][1]>temp.back()) temp.push_back(envelopes[i][1]);
            else{
                int idx=lower_bound(temp.begin(),temp.end(),envelopes[i][1])-temp.begin();
                temp[idx]=envelopes[i][1];
            }
        }
        return temp.size();
    }
};