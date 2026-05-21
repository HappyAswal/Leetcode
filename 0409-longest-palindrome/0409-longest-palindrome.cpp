class Solution {
public:
    int longestPalindrome(string s) {
        unordered_map<int,int>freq;
        for(char c:s) freq[c]++;

        int ans=0;
        bool odd=false; //odd len check
        for(auto x:freq){
            int f=x.second;
            //even number of times "a" appears
            if(f%2==0){
                ans+=f;
            }
            // a->1 b->1 z->1 use only one
            else{
                ans+=f-1;
                //v->3 time so 3-1=2 even times
                odd=true;
            }
        }
        if(odd) ans+=1;
        return ans;
    }
};