class Solution {
public:
    int maxDepth(string s) {
        int balance=0;
        int result=INT_MIN;
        for(int i=0;i<s.size();i++){
            if(s[i]=='('){
                balance++;
            }else if(s[i]==')'){
                balance--;
            }
            result=max(result,balance);
        }
        return result;
        
    }
};