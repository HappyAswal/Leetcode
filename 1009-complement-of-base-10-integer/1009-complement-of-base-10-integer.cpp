class Solution {
public:
    int bitwiseComplement(int n) {
        if(n==0) return 1;
        int result=0;
        int count=0;
        while(n>0){
            int d=n%2;
            result+=(pow(2,count++)*!d);
            n/=2;
        }
        return result;
    }
};