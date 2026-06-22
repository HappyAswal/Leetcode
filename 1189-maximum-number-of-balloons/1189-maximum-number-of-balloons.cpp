class Solution {
public:
    int maxNumberOfBalloons(string text) {
        unordered_map<char,int>fq;
        for(char c:text) fq[c]++;
        int b_count=0;

        int f1=min({fq['b'],fq['a'],fq['n']});
        if(f1==0) return 0;

        int f2=min(fq['l'],fq['o']);
        if(f2<=1) return 0;

        b_count=min(f1,f2/2);
        return b_count;
    }
};