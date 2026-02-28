class Solution {
public:
    int concatenatedBinary(int n) {
        long long result=0;
        int m=1e9+7;
        for(int num=1;num<=n;num++){
            int digit=(int)log2(num)+1;
            result=((result<<digit)%m+num)%m;
        }
        return result;
    }
};