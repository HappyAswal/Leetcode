class Solution {
public:
    double myPow(double x, int n) {
        double ans=1.0;
        long long dn=n;
        if(dn<0) dn=-dn;

        while(dn>0){
            if(dn%2==1){
                ans=ans*x;
                dn=dn-1;
            }
            else{
                x=x*x;
                dn=dn/2;
            }
        }
        if(n<0) return 1.0/ans;
        return ans;

    }
};