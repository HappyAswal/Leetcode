class Solution {
public:
    bool checkprime(int n){
        if(n<=1) return false;
        if(n<=3) return true;
        if(n%2==0 || n%3==0) return false;
        for(int i=5;i*i<=n;i++){
            if(n%i==0) return false;
        }
        return true;
    }
    vector<int> closestPrimes(int left, int right) {
        vector<int>primes;
        for(int i=left;i<=right;i++){
            if(checkprime(i)) primes.push_back(i);
        }
        vector<int>ans;
        if(primes.size()==1 || primes.size()==0) return {-1,-1};
        if(primes.size()==2) return primes;
        int diff=INT_MAX;
        for(int i=0;i<primes.size()-1;i++){
            int df=primes[i+1]-primes[i];
            if(df<diff){
                ans={primes[i],primes[i+1]};
                diff=df;
            }
        }
        return ans;
    }
};