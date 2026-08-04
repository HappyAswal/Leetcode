class Solution {
public:
    int countValidPrefixes(string s) {
        int zeros=0,ones=0;
        int count=0;
        for(char c:s){
            if(c=='1') ones++;
            else zeros++;
            //check current count
            if(ones==zeros+1 || zeros==ones+1 || zeros==ones) count++;
        }
        return count;
    }
};