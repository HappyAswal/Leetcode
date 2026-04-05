class Solution {
public:
    bool judgeCircle(string moves) {
        // U D L R
        int dx[4]={-1,1,0,0};
        int dy[4]={0,0,-1,1};
        int i=0,j=0;
        for(char c:moves){
            if(c=='U') i+=dx[0],j+=dy[0];
            if(c=='D') i+=dx[1],j+=dy[1];
            if(c=='L') i+=dx[2],j+=dy[2];
            if(c=='R') i+=dx[3],j+=dy[3];
        }
        return (i==0 && j==0);
    }
};