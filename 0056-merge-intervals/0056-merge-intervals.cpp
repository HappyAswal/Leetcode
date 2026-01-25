class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& iv) {
        sort(iv.begin(),iv.end());
        int n=iv.size();
        vector<int> comp=iv[0];
        vector<vector<int>>ans;
        for(int i=1;i<n;i++){
            if(iv[i][0]<=comp[1]){
                //overlap
                comp[1]=max(comp[1],iv[i][1]);
            }else{
                ans.push_back(comp);
                comp=iv[i];
            }
        }
        ans.push_back(comp);
        return ans;
    }
};