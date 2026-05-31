class Solution {
public:
    int digitFrequencyScore(int n) {
        vector<int>freq(10,0);
        int sum=0;
        while(n>0){
            int digit=n%10;
            freq[digit]++;
            n=n/10;
        }
        for(int i=0;i<10;i++){
            sum+=i*freq[i];
        }
        return sum;
    }
};