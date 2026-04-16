class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string ans="";
        sort(strs.begin(),strs.end());
        string start=strs.front();
        string end=strs.back();
        for(int i=0;i<min(start.size(),end.size());i++){
            if(start[i]==end[i]) ans.push_back(start[i]);
            else break;
        }
        return ans;
    }
};