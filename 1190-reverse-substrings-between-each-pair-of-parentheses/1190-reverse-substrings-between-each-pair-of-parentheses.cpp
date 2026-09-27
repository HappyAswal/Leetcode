class Solution {
public:
    string reverseParentheses(string s) {
        stack<int>len;
        string res="";
        for(char c:s){
            if(c=='(') len.push(res.size());
            else if(c==')'){
                int skip=len.top(); 
                len.pop();
                reverse(res.begin()+skip,res.end());
            }else res.push_back(c);
        }
        return res;
    }
};