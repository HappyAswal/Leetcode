class Solution {
public:
    int mirrorDistance(int n) {
        if(n<10) return 0;
        int x=n;
        int num=0;
        while(x>0){
            int d=x%10;
            num=num*10+d;
            x/=10;
        }
        return abs(n-num);
    }
};