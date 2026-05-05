class Solution {
public:
    bool isprime(int x){
        if(x<=1) return false;
        if(x<=3) return true;
        if(x%2==0||x%3==0) return false;
        for(int i=5;i*i<=x;i++){
            if(x%i==0) return false;
        }
        return true;
    }
    int sumOfPrimesInRange(int n) {
        int d=0;
        int x=n;
        while(x>0){
            int dig=x%10;
            d=d*10+dig;
            x/=10;
        }
        int count=0;
        for(int i=min(d,n);i<=max(d,n);i++){
            if(isprime(i)) count+=i;
        }
        return count;
    }
};