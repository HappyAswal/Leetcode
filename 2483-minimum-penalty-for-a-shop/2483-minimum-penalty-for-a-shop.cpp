class Solution {
public:
    int bestClosingTime(string customers) {
        int n=customers.size();
        int mH=0;
        int penalty=count(customers.begin(),customers.end(),'Y');
        int mpenalty=penalty;

        for(int i=0;i<n;i++){
            if(customers[i]=='Y') penalty--;
            else penalty++;
            if(penalty<mpenalty){
                mpenalty=penalty;
                mH=i+1;
            }
        }
        return mH;
    }
};