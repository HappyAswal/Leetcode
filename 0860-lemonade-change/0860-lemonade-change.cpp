class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int b5=0,b10=0;
        for(int x:bills){
            if(x==5) b5++;
            if(x==10){
                if(b5>0){
                    b10++;
                    b5--;
                }else return false;
            }
            if(x==20){
                if(b10>0 && b5>0){
                    b10--; b5--;
                }
                else if(b5>2){
                    b5-=3;
                }
                else return false;
            }
        }
        return true;
    }
};