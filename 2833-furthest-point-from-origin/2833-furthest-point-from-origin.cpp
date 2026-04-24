class Solution {
public:
    int furthestDistanceFromOrigin(string moves) {
        string s1=moves;
        string s2=moves;
        int n=moves.size();
        for(char&c:s1){
            if(c=='_') c='L';
        }
        for(char&c:s2){
            if(c=='_') c='R';
        }
        int c1l=0;
        int c1r=0;
        for(char c:s1){
            if(c=='L') c1l++;
            else c1r++;
        }
        int count1=abs(c1l-c1r);

        int c2l=0;
        int c2r=0;
        for(char c:s2){
            if(c=='L') c2l++;
            else c2r++;
        }
        int count2=abs(c2l-c2r);

        return max(count1,count2);
    }
};