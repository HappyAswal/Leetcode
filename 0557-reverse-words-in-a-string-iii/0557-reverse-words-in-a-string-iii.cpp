class Solution {
public:
    string reverseWords(string s) {
        string ans="";
        string temp="";
        for(char c:s){
            if(c==' '){
                reverse(temp.begin(),temp.end());
                ans+=temp;
                ans+=' ';
                temp="";
            }
            else temp+=c;
        }
        reverse(temp.begin(),temp.end());
        ans+=temp;
        return ans;
    }
};