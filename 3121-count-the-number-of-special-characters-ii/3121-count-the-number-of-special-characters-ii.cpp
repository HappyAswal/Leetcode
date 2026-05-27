class Solution {
public:
    int numberOfSpecialChars(string word) {
        vector<int>l_lower(26,-1); //last occurance of any small c
        vector<int>f_upper(26,-1); //first occurance of c as Captial C

        for(int i=0;i<word.size();i++){
            char c=word[i];
            if(islower(c)){
                l_lower[c-'a']=i;
            }else{
                if(f_upper[c-'A']==-1){
                    f_upper[c-'A']=i;
                }
            }
        }
        int count=0;
        for(int i=0;i<26;i++){
            if(l_lower[i]!=-1 && f_upper[i]!=-1 && l_lower[i]<f_upper[i]){
                count++;
            }
        }
        return count;
    }
};