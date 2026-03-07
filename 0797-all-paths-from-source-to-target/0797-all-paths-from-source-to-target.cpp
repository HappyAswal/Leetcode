class Solution {
public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<vector<int>>ans;
        int n=graph.size();
        queue<vector<int>>q;
        vector<int>path={0};
        q.push(path);
        while(!q.empty()){
            vector<int>p=q.front();
            q.pop();
            int currn=p.back();
            if(currn==n-1){
                ans.push_back(p);
                continue;
            }
            for(auto x:graph[currn]){
                vector<int>temp=p;
                temp.push_back(x);
                q.push(temp);
            }
        }
        return ans;
    }
};