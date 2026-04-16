class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& inl) {
        sort(inl.begin(),inl.end());
        vector<int>compare=inl[0];
        vector<vector<int>>ans;
        for(int i=1;i<inl.size();i++){
            if(inl[i][0]<=compare[1]){
                compare[1]=max(compare[1],inl[i][1]);
            }else{
                ans.push_back(compare);
                compare=inl[i];
            }
        }
        ans.push_back(compare);
        return ans;
    }
};