class Solution {
public:
    bool ispalindrome(int i,int j,string& s){
        while(i<j){
            if(s[i]!=s[j]) return false;
            else i++,j--;
        }
        return true;
    }
    string longestPalindrome(string s) {
        string ans="";
        int ii=0,jj=0;
        int count=1;
        for(int i=0;i<s.size();i++){
            for(int j=i+1;j<s.size();j++){
                if(ispalindrome(i,j,s)){
                    if(j-i+1>count){
                        count=j-i+1;
                        ii=i,jj=j;
                    }
                }
            }
        }
        return s.substr(ii,jj-ii+1);
    }
};