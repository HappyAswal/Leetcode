class Solution {
public:

    int bestClosingTime(string customers) {
        int n=customers.size();
        vector<int> prefixN(n+1,0); 
        prefixN[0]=0; // 0 se phli kitni penalty
        vector<int> suffixY(n+1,0);
        suffixY[n]=0; // last time ke bad kitni penalty
        for(int i=1;i<=n;i++){
            if(customers[i-1]=='N') prefixN[i]=prefixN[i-1]+1;
            else prefixN[i]=prefixN[i-1];
        }
        for(int i= n-1;i>=0;i--){
            if(customers[i]=='Y') suffixY[i]=suffixY[i+1]+1;
            else suffixY[i]=suffixY[i+1];
        }
        int mP=INT_MAX,mH=INT_MAX;
        for(int i=0;i<=n;i++){
            int cP=prefixN[i]+suffixY[i];
            if(cP<mP){
                mP=cP;
                mH=i;
            }
        }
        return mH;
    }
};