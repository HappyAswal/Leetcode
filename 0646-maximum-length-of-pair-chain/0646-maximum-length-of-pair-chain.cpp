class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        sort(pairs.begin(), pairs.end(), [](auto &a, auto &b){
            return a[1] < b[1];
        });
        vector<int>chain;
        chain.push_back(pairs[0][1]);
        int i=1,j=0;
        while(i<pairs.size()){
            if(chain[j]<pairs[i][0]){
                chain.push_back(pairs[i][1]);
                j++,i++;
            }
            else i++;
        }
        return chain.size();
    }
};