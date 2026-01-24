class Solution {
public:
    bool isPalindrome(int x) {
        long long rev=0;
        int y=x;
        if(x<0) return false;
        while(x!=0){
             int ld=x%10;
             x=x/10; 
             rev=rev*10+ld;
        }
        if (rev==y) return true;
        return false;
    }
};