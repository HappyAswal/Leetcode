class Solution {
public:
    string addBinary(string a, string b) {
        int n=a.size()-1;
        int m=b.size()-1;
        string res="";
        int sum=0;
        int carry=0;
        while(n>=0 || m>=0){
            int sum=carry;
            if(n>=0){
                sum+=a[n]-'0';
                n--;
            }
            if(m>=0){
                sum+=b[m]-'0';
                m--;
            }
            res.push_back((sum%2==0)?'0':'1');
            carry=(sum>1)?1:0;
        }
        if(carry==1) res.push_back('1');
        reverse(res.begin(),res.end());
        return res;
    }
};