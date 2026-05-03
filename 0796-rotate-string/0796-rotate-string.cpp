class Solution {
public:
    bool rotateString(string s, string goal) {
        if(s.size()!=goal.size()) return false;

        string check=s+s;

        if(check.find(goal) != string::npos) return true;
        return false;
    }
};