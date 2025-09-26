class Solution {
public:
    int myAtoi(string s) {
        if(s.empty()) return 0;
        int result=0;
        int i=0;
        int sign=1;
        //ignore spaces
        while(i<s.size() && s[i]== ' ') i++;
        //sign + or -
        if(i < s.size() && s[i]=='-'){
            sign=-1;
            i++;
        }else if(i < s.size() && s[i]=='+'){
            i++;
        }

        while(i<s.size()){
            if(!isdigit(s[i])) break;
            int digit= s[i]-'0';
            
            //overflow
            if(result>(INT_MAX-digit)/10){
                return(sign==1) ? INT_MAX: INT_MIN;
            }
            //condition ? value_if_true : value_if_false
            result = result * 10 + digit;
            i++;
        }
        return result*sign;
    }
};