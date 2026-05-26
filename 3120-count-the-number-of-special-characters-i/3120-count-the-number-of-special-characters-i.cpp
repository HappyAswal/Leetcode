class Solution {
public:
    int numberOfSpecialChars(string word) {
        unordered_set<char>st={word.begin(),word.end()};
        int count=0;
        for(char c:st){
            if(islower(c)){
                if(st.count(toupper(c))) count++;
            }
        }
        return count;
    }
};