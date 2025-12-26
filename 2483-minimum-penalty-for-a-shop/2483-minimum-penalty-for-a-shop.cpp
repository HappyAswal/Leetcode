class Solution {
public:
    int penalty(string& customers,int i){
        int penalty=0;
        for(int j=0;j<i;j++){
            if(customers[j]=='N') penalty+=1;
        }
        for(int k=i;k<customers.size();k++){
            if(customers[k]=='Y') penalty+=1;
        }
        return penalty;
    }
    int bestClosingTime(string customers) {
        int n = customers.size();
        int ans = 0;
        int minPenalty = INT_MAX;
        for(int i=0;i<=n;i++){
            int p=penalty(customers,i);
            if(p<minPenalty){
                minPenalty=p;
                ans=i;
            }
        }
        return ans;
    }
};