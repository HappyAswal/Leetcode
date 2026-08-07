class Solution {
public:
    vector<int>digits;
    void fxn(int n){
        while(n>0){
            int d=n%10;
            n/=10;
            digits.push_back(d);
        }
    }
    int maxProduct(int n) {
        fxn(n);
        sort(digits.begin(),digits.end());
        int nn=digits.size();
        int ans=digits[nn-1]*digits[nn-2];
        return ans;
    }
};