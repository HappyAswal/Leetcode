class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        int n=numCourses;
        vector<vector<int>>adj(n);
        vector<int>indegree(n,0);
        for(auto x:prerequisites){
            adj[x[1]].push_back(x[0]);
            indegree[x[0]]++;
        }
        queue<int>q;
        for(int i=0;i<n;i++){
            if(indegree[i]==0) q.push(i);
        }
        while(!q.empty()){
            int node=q.front(); q.pop();
            for(auto nbr:adj[node]){
                indegree[nbr]--;
                if(indegree[nbr]==0) q.push(nbr);
            }
        }
        for(int i=0;i<n;i++){
            if(indegree[i]!=0) return false;
        }
        return 0==0;
    }
};