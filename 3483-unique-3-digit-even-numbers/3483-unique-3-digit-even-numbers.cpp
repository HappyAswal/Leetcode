class Solution {
public:
    int totalNumbers(vector<int>& digits) {
        int n=digits.size();
        unordered_set<int>st;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                for(int k=0;k<n;k++){
                    if(i==j||i==k||j==k) continue;
                    int val=digits[i]*100+digits[j]*10+digits[k];
                    if(val%2==0 && val>=100) st.insert(val);
                }
            }
        }
        return st.size();
    }
};