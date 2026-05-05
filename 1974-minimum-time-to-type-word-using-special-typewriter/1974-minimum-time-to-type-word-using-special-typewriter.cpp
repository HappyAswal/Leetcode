class Solution {
public:
    int minTimeToType(string word) {
        int time=0;
        char p='a';
        for(char c:word){
            int dist= abs(c-p);
            int t=min(dist,26-dist);
            time+=t+1;
            p=c;
        }
        return time;
    }
};