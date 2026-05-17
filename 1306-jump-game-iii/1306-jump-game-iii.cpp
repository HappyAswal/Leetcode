class Solution {
public:
    vector<int>vis;
    bool check(int i,vector<int>& arr){
        if(i>=arr.size()) return false;
        if(i<0) return false;
        if(vis[i]) return false;
        if(arr[i]==0) return true;
        vis[i]=true;
        bool jl=check(i-arr[i],arr);
        bool jr=check(i+arr[i],arr);
        return jl||jr;
    }
    bool canReach(vector<int>& arr, int start) {
        vis.assign(arr.size(),false);
        return check(start,arr);
    }
};