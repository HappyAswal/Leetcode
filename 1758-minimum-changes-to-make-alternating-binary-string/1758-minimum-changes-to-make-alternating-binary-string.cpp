class Solution {
public:
    int minOperations(string s) {
        int pat1=0; //0101..
        int pat2=0; //1010..
        for(int i=0;i<s.size();i++){
            if(i%2==0){
                if(s[i]=='0') pat2++;
                else pat1++;
            }else{
                if(s[i]=='1') pat2++;
                else pat1++;
            }
        }
        return min(pat1,pat2);
    }
};