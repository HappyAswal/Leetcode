class Solution {
public:
    int passwordStrength(string password) {
        unordered_set<char>st;
        unordered_set<char>sp={'!','@','#','$'};
        for(char c:password) st.insert(c);
        int points=0;
        for(char c:st){
            if(isalpha(c) && islower(c)) points+=1;
            if(isalpha(c) && isupper(c)) points+=2;
            if(isdigit(c)) points+=3;
            if( sp.count(c)) points+=5;
        }
        return points;
    }
};