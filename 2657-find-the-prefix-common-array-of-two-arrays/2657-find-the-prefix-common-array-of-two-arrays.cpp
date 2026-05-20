class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        vector<int>ans;
        int idx=0;
        while(idx<A.size()){
            int count=0;
            unordered_set<int>st;
            for(int i=0;i<=idx;i++){
                st.insert(A[i]);
            }
            for(int i=0;i<=idx;i++){
                if(st.count(B[i])) count++;
            }
            ans.push_back(count);
            idx++;
        }
        return ans;
    }
};