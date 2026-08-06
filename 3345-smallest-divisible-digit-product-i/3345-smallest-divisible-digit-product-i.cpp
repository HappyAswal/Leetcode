class Solution {
public:
    int prod(int n){
        int num=1;
        while(n>0){
            int d=n%10;
            n/=10;
            num*=d;
        }
        return num;
    }
    int smallestNumber(int n, int t) {
        int num=n;
        while(true){
            int x=prod(num);
            if(x==0) return num;
            if(x%t==0){
                return num;
            }
            else num++;
        }
        return -1;
    }
};