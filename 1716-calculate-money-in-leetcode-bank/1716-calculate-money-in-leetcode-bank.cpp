class Solution {
public:
    int totalMoney(int n) {
        int s_monday=1;
        int sum=0;
        while(n>0){
            int money=s_monday;
            for(int i=1;i<=min(n,7);i++){
                sum=sum+money;
                money++;
            }
            
            n=n-7;
            s_monday++;
        }
        return sum;
        
    }
};