class Solution {
public:
    bool palandrome(int i, int j, string& s){
        if(i>=j) return true;
        if(s[i]==s[j]) return palandrome(i+1,j-1,s);
        return false;
    }
    string longestPalindrome(string s) {
        int start;
        int mxlen=INT_MIN;
        int n=s.size();
        for(int i=0;i<n;i++){
            for(int j=i;j<n;j++){
                if(palandrome(i,j,s) && j-i+1>mxlen){
                    mxlen=j-i+1; 
                    start=i;
                }
            }
        }
        return s.substr(start,mxlen);
    }
};