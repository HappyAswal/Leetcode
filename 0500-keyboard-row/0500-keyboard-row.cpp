class Solution {
public:
    vector<string> findWords(vector<string>& words) {
        vector<string>ans;
        unordered_set<char>st1={'q','Q','w','W','e','E','r','R','t','T','y','Y','u','U','i','I','o','O','p','P'};
        unordered_set<char>st2={'a','A','s','S','d','D','f','F','g','G','h','H','j','J','k','K','l','L'};
        unordered_set<char>st3={'z','Z','x','X','c','C','v','V','b','B','n','N','m','M'};

        for(string abc:words){
            bool f1=true;
            for(char c:abc){
                if(st1.find(c)==st1.end()){
                    f1=false;
                    break;
                }
            }
            bool f2=true;
            for(char c:abc){
                if(st2.find(c)==st2.end()){
                    f2=false;
                    break;
                }
            }
            bool f3=true;
            for(char c:abc){
                if(st3.find(c)==st3.end()){
                    f3=false;
                    break;
                }
            }
            if(f1||f2||f3) ans.push_back(abc);
        }
        return ans;
    }
};