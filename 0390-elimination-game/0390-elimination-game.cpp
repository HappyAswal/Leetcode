class Solution {
public:
    int solve(int head,int diff,bool flag, int n){
        if(n==1) return head;
        if(flag || n%2 == 1) head+= diff;
        return solve(head, diff*2,!flag, n/2);
    }
    int lastRemaining(int n) {
        return solve(1,1,true,n);
    }
};