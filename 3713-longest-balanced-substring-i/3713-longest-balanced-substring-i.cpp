class Solution {
public:
    bool checkbalance(vector<int>&freq){
        int cf=0;
        for(int i=0;i<26;i++){
            if(freq[i]==0) continue;
            if(cf==0) cf=freq[i];
            else if(freq[i]!=cf) return false;
        }
        return true;
    }
    int longestBalanced(string s) {
        int n=s.size();
        int maxl=0;
        for(int i=0;i<n;i++){
            vector<int>freq(26,0);
            for(int j=i;j<n;j++){
                freq[s[j]-'a']++;
                if(checkbalance(freq)){
                    maxl=max(maxl,j-i+1);
                }
            }
        }
        return maxl;
    }
};