class Solution {
public:
    bool wordPattern(string pattern, string s) {
        istringstream ss(s);
        vector<string>words;
        string w;

        unordered_map<char,string>m1;
        unordered_map<string,char>m2;

        while(ss>>w){
            words.push_back(w);
        }
        if(pattern.size()!=words.size()) return false;

        for(int i=0;i<pattern.size();i++){
            char ch=pattern[i];
            string st=words[i];
            if(m1.find(ch)!=m1.end() && m1[ch]!=st){
                return false;
            }
            else if(m2.find(st)!=m2.end()&& m2[st]!=ch){
                return false;
            }else{
                m1[ch]=st;
                m2[st]=ch;
            }
        }
        return true;
    }
};