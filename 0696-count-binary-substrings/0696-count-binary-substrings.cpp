class Solution {
public:
    int countBinarySubstrings(string s) {
        int res=0;
        int curr=1,prev=0;
        for(int i=1;i<s.size();i++){
            if(s[i]==s[i-1]){
                curr++;
            }else{
                res+=min(prev,curr);
                prev=curr;
                curr=1;
            }
        }
        return res+min(prev,curr);
    }
};