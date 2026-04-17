class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n=s.size();
        int maxl=0;
        unordered_set<char>st;
        int left=0;
        int currmax=0;
        for(int i=0;i<n;i++){
            while(st.find(s[i])!=st.end()){
                st.erase(s[left]);
                left++;
                currmax--;
            }
            st.insert(s[i]);
            currmax++;
            maxl=max(maxl,currmax);
        }
        return maxl;
    }
};