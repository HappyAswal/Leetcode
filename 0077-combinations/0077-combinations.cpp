class Solution {
public:
    vector<vector<int>>ans;
    vector<int>curr;
    void result(int l,int r,int k){
        if(curr.size()==k){ 
            ans.push_back(curr);
            return;
        }
        for(int i=l;i<=r;i++){
            curr.push_back(i);
            result(i+1,r,k);
            curr.pop_back();
        }
    }
    vector<vector<int>> combine(int n, int k) {
        result(1,n,k);
        return ans;
    }
};