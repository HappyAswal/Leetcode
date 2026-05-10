class Solution {
public:
    int compress(vector<char>& chars) {
        if(chars.size()==1) return 1;
        int count=1;
        string ans="";
        for(int i=0;i<chars.size();i++){
            if(i<chars.size()-1 && chars[i]==chars[i+1]){
                count++;
            }
            else{
                ans+=chars[i];
                if(count>1) ans+=to_string(count);
                count=1;
            }
        }
        for(int i=0;i<ans.size();i++){
            chars[i]=ans[i];
        }
        return ans.size();
    }
};