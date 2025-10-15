class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        int t1=0,t2=0;
        for(int s1: students){
            if(s1==0) t2++;
            else t1++;
        }
        for(int s : sandwiches){
            if(s==0 && t2==0) return t1;
            if(s==1 && t1==0) return t2;
            if(s==0) t2--;
            else t1--;
        }
        return 0;

    }
};