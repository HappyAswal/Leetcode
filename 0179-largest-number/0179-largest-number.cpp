class Solution {
public:
    string largestNumber(vector<int>& nums) {
        vector<string>ans;
        for(int i:nums) ans.push_back(to_string(i));

        sort(ans.begin(),ans.end(),[](auto&a,auto&b){
            return a+b>b+a;
        });
        if(ans[0]=="0") return "0";
        string res="";
        for(string& s: ans) res+=s;
        return res;
    }
};