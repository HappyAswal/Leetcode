class Solution {
public:
    string processStr(string s) {
        string res="";
        for(char c: s){
            if(isalpha(c)) res+=c;
            if(!res.empty() && c=='*') res.pop_back();
            if(c=='#') res+=res;
            if(!res.empty() && c=='%') reverse(res.begin(),res.end());
        }
        return res;
    }
};