class Solution {
public:
    bool isPalindrome(string s) {
        string check="";
        for(char c:s){
            if(isalnum(c)) check+=tolower(c);
        }
        int i=0, j=check.size()-1;
        while(i<j){
            if(check[i]==check[j]){
                i++,j--;
            }else return false;
        }
        return true;

    }
};